using static System.Console;
static class Progr {
    static void Main()
    {
        var Game = new Bulls_and_Cows();
        Game.Run();
    }
}

class Bulls_and_Cows{
    bool HaveSecondP = false;
    String question_First_Player = ""; 
    String answer_First_Player = "#";
    String question_Second_Player = "";
    String answer_Second_Player = "#";
    int quantity_of_attemps_First_Player = 0;
    int quantity_of_attemps_Second_Player = 0;
    bool refusal_to_play_First_Player = false;
    bool refusal_to_play_Second_Player = false;
    int difficult = 4;

    // TEXT
    String text_Input = "Введите предполагаемое значение (может начинаться с нуля): ";
    String text_Bye = "Заходи ещё!";
    String text_choose_difficult = "Выберите сложность игры (4 до 10 (угадываемых цифр)): ";
    String text_choose_AGAIN = "Введите пожалуйста!";
    private static String text_FAQ = "Система (или игроки) загадывают X-значное выражение с неповторяющимися десятичными цифрами, которое необходимо угадать!\n" +
                  "Количество коров означает количество цифр в вашей записи, которые также имеются и в искомой записи, но НЕ СОВПАДАЮТ с их позициями.\n" +
                  "Количество быков же означает количество цифр, которые совпадают по позиции тоже.\n\n";
    // TEXT
    String Input()
    {
        String inp = "";
        while (true)
        {
            var key = ReadKey(true);
            if (key.Key == ConsoleKey.Enter)
                break;
            inp += key.KeyChar;
        }
        return inp;
    }
    void Have_Second_Player()
    {
        WriteLine("Вас двое? Y or N");
        String? choice = "";
        int i = 1;
        do
        {
            choice = ReadLine();
            if (!String.IsNullOrEmpty(choice))
            {
                HaveSecondP = (choice.ToCharArray()[0] == 'Y' || choice.ToCharArray()[0] == 'y');
            }
            else
            {
                if (i == 10)
                {
                    HaveSecondP = false;
                    break;
                }
                WriteLine(text_choose_AGAIN);
            }
            i++;
        }while(String.IsNullOrEmpty(choice));
    }
    bool Verification(String Combination, out String error)
    {
        if (Combination == null)
        {
            error = "Вы должны написать хоть что то!";
        }
        else if ((Combination.ToHashSet().Count != difficult) && (Combination.All(s => Char.IsDigit(s))))
        {
            error = $"Вы должны написать число, состоящее ровно из {difficult} цифр!";
        }
        else if((Combination.Any(s => !Char.IsDigit(s))) && (Combination.ToHashSet().Count == difficult))
        {
            error = "Вы должны ввести значение, состоящее лишь из ЦИФР!";
        }
        else if ((Combination.ToHashSet().Count != difficult) && (Combination.Any(s => !Char.IsDigit(s))))
        {
            error = $"Вы должны написать набор из {difficult} символов, включающий в себя ТОЛЬКО ЦИФРЫ!";
        }
        else
        {
            error = "";
        }
        return String.IsNullOrEmpty(error);
    }
    int check_bulls(String ans, String ques, int n = 4)
    {
        int counter = 0;
        for(int i = 0; i < n; ++i)
        {
            if (ans[i] == ques[i])
            {
                counter++;
            }
        }
        return counter;
    }
    int check_cows(String ans, String ques, int n = 4)
    {
        int counter = 0;
        for(int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)// Ctrl + r + r - замена всех имён, чотко)))
            {
                if ((ans[i] == ques[j]) && (i!=j))
                {
                    counter++;
                }
            }
        }
        return counter;
    }
    void choose_difficult()
    {
        int diff = 0;
        WriteLine(text_choose_difficult);
        do
        {
            var temp = ReadLine();
            if (!String.IsNullOrEmpty(temp))
            {
                diff = Convert.ToInt32(temp);
            }
            else
            {
                WriteLine(text_choose_AGAIN);
            }
        } while (!(diff >= 4 && diff <= 10));

        difficult = diff;
    }
    void FAQ()
    {

        WriteLine(text_FAQ);
    }
    void Init()
    {
        if (HaveSecondP)
        {
            WriteLine($"Первый игрок:\nЗагадайте комбинацию неповторяющихся {difficult}-х значных цифр: ");
            do
            {
                question_First_Player = Input();
                if (!Verification(question_First_Player, out String error))
                {
                    WriteLine(text_choose_AGAIN);
                }
                else
                {
                    break;
                }
            } while (true);
            WriteLine($"Второй игрок:\nЗагадайте комбинацию неповторяющихся {difficult}-х значных цифр: ");
            do
            {
                question_Second_Player = Input();
                if (!Verification(question_Second_Player, out String error))
                {
                    WriteLine(text_choose_AGAIN);
                }
                else
                {
                    break;
                }
            } while (true);
        }
        else
        {
            refusal_to_play_Second_Player = true;
            Random rnd = new Random();
            char[] abc = "0123456789".ToCharArray();
            for (int i = 0; i < difficult; ++i)
            {
                int j = rnd.Next(0, 10);
                (abc[i], abc[j]) = (abc[j], abc[i]);
            }
            question_Second_Player = new string(abc[..difficult]);
        }
    }
    void Loop()
    {
        int FlipFlop = 1;
        do
        {
            //Угадывает Второй игрок 
            if (((HaveSecondP) && (FlipFlop % 2 == 1)&&(!refusal_to_play_Second_Player))||((HaveSecondP)&&(refusal_to_play_First_Player)))
            {
                Write("\t\t\t\t" + "Игрок Второй, " +  text_Input);
                answer_Second_Player = ReadLine();
                if (String.IsNullOrEmpty(answer_Second_Player))
                {
                    refusal_to_play_Second_Player = true;
                }
                if (Verification(answer_Second_Player, out string error))
                {
                    FlipFlop++;
                    quantity_of_attemps_Second_Player++;
                    var bulls = check_bulls(answer_Second_Player, question_First_Player, difficult);
                    var cows = check_cows(answer_Second_Player, question_First_Player, difficult);
                    String text_info_of_step = $"Количество быков: {bulls};\n\t\t\t\tКоличество коров: {cows};";
                    WriteLine("\t\t\t\t" + text_info_of_step);
                    if (bulls == difficult)
                    {
                        String text_Win = $"Вы (Игрок 2) выиграли с {quantity_of_attemps_Second_Player} попытки!";
                        WriteLine("\t\t\t\t" + text_Win);
                    }
                }
                else
                {
                    WriteLine("\t\t\t\t" + error);
                }
            }
            //Угадывает Первый игрок, либо тот, кто единственный.
            else if (!refusal_to_play_First_Player)
            {
                if (HaveSecondP)
                {
                    Write("\nИгрок Первый, " + text_Input);
                }
                else
                {
                    Write("\n" + text_Input);
                }
                answer_First_Player = ReadLine();
                if (String.IsNullOrEmpty(answer_First_Player))
                {
                    refusal_to_play_First_Player = true;
                }
                if (Verification(answer_First_Player, out string error))
                {
                    FlipFlop++;
                    quantity_of_attemps_First_Player++;
                    var bulls = check_bulls(answer_First_Player, question_Second_Player, difficult);
                    var cows = check_cows(answer_First_Player, question_Second_Player, difficult);
                    String text_info_of_step = $"Количество быков: {bulls};\nКоличество коров: {cows};";
                    WriteLine(text_info_of_step);
                    if (bulls == difficult)
                    {
                        String text_Win = $"Вы (Игрок 1) выиграли с {quantity_of_attemps_First_Player} попытки!";
                        WriteLine(text_Win);
                    }
                }
                else
                {
                    WriteLine(error);
                }
            }
            
        } while (((answer_First_Player != question_Second_Player) && (!refusal_to_play_First_Player)) ||
            (answer_Second_Player != question_First_Player) && (!refusal_to_play_Second_Player));
    }

    public void Run()
    {
        FAQ();
        Have_Second_Player();
        choose_difficult();
        Init();
        Loop();
        WriteLine(text_Bye);
    }
}