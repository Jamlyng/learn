#pragma once
#include <iostream>
#include <string>
class point_in_3d {
private:
	double x;
	double y;
	double z;
public:
	point_in_3d() : x(0.0), y(0.0), z(0.0) {}
	void set(double a, double b, double c) {
		x = a; y = b; z = c;
	}
	double get_x() {
		return x;
	}
	double get_y() {
		return y;
	}
	double get_z() {
		return z;
	}
};
class vector_in_3d {
private:
	point_in_3d A;
	point_in_3d B;
	double x_coord;
	double y_coord;
	double z_coord;
public:
	vector_in_3d() {
		A.set(0, 0, 0);
		B.set(0, 0, 0);
		x_coord = 0;
		y_coord = 0;
		z_coord = 0;
	}
	vector_in_3d(double a1, double b1, double z1, double a2, double b2, double z2) {
		A.set(a1, b1, z1);
		B.set(a2, b2, z2);
		x_coord = B.get_x() - A.get_x();
		y_coord = B.get_y() - A.get_y();
		z_coord = B.get_z() - A.get_z();
	}
	double module() {
		double temp = sqrt(pow(((B.get_x()) - (A.get_x())), 2) + pow(((B.get_y()) - (A.get_y())), 2) + pow(((B.get_z()) - (A.get_z())), 2));
		if (temp > 0) return temp;
		else return ((-1) * temp);
	}
	void coord() {
		double a = (B.get_x() - A.get_x());
		double b = (B.get_y() - A.get_y());
		double c = (B.get_z() - A.get_z());
		std::cout << '(' << a << ';' << b << ';' << c << ')' << std::endl;
	}
	void set_A(double a, double b, double c) {
		A.set(a, b, c);
	}
	void set_B(double a, double b, double c) {
		B.set(a, b, c);
	}
	double multiply(vector_in_3d X) {
		return ((X.get_coord_x() * get_coord_x()) + (X.get_coord_y() * get_coord_y()) + (X.get_coord_z() * get_coord_z()));
	}
	double angle_radian(vector_in_3d X) {
		return acos(multiply(X) / (X.module() * module()));
	}
	double angle_degree(vector_in_3d X) {
		return (acos(multiply(X) / (X.module() * module())) * 180 / 3.1415);
	}
	void update() {
		x_coord = B.get_x() - A.get_x();
		y_coord = B.get_y() - A.get_y();
		z_coord = B.get_z() - A.get_z();
		return;
	}
	double get_coord_x() {
		return x_coord;
	}
	double get_coord_y() {
		return y_coord;
	}
	double get_coord_z() {
		return z_coord;
	}
	double A_x() {
		return A.get_x();
	}
	double A_y() {
		return A.get_y();
	}
	double A_z() {
		return A.get_z();
	}
	double B_x() {
		return B.get_x();
	}
	double B_y() {
		return B.get_y();
	}
	double B_z() {
		return B.get_z();
	}
};

void print_all_data(vector_in_3d& AB, vector_in_3d& CD);
void user_interface();
double* print_interface(int number_of_vector);
void error();

void print_all_data(vector_in_3d& AB, vector_in_3d& CD) {
	std::cout << "AB: {\n\tA: {x: " << AB.A_x() << "; y: " << AB.A_y() << "; z: " << AB.A_z() << "}\n"
			  << "\tB: {x: " << AB.B_x() << "; y: " << AB.B_y() << "; z: " << AB.B_z() << "}\n}\n"
			  << "CD: {\n\tC: {x: " << CD.A_x() << "; y: " << CD.A_y() << "; z: " << CD.A_z() << "}\n"
			  << "\tD: {x: " << CD.B_x() << "; y: " << CD.B_y() << "; z: " << CD.B_z() << "}\n}\n" << std::endl;
}
void user_interface() {
	bool quit = 0;
	double* Coord;
	while (true) {
		Coord = print_interface(1);
		if (Coord[0] == Coord[3] && Coord[1] == Coord[4] && Coord[2] == Coord[5]) {
			std::cout << "The vector can't be null.\n";
			system("PAUSE");
			system("cls");
		}
		else {
			break;
		}
	}
	vector_in_3d AB(Coord[0], Coord[1], Coord[2], Coord[3], Coord[4], Coord[5]);
	while (true) {
		Coord = print_interface(2);
		if (Coord[0] == Coord[3] && Coord[1] == Coord[4] && Coord[2] == Coord[5]) {
			std::cout << "The vector can't be null.\n";
			system("PAUSE");
			system("cls");
		}
		else {
			break;
		}
	}
	vector_in_3d CD(Coord[0], Coord[1], Coord[2], Coord[3], Coord[4], Coord[5]);
	system("PAUSE");
	system("cls");
	do {
		std::cout << "Choose:\n\t1: Get coordinate of your vector.\n\t2:Change vector.\n\t3: Get angle between vectors.\n\t4: Get module of vector.\n\t"
			<< "5: Get the scalar product.\n\t6: Get full info.\n\t7: Quit.\n";
		int choice;
		std::cout << "Input choice:";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			int temp_choice = 0;
			std::cout << "What vector:\n\t1: AB\n\t2: CD\n";
			std::cin >> temp_choice;
			switch (temp_choice) {
			case 1: {
				AB.coord();
				break;
			}
			case 2: {
				CD.coord();
				break;
			}
			default: {
				error();///
				break;
			}
			}
			break;
		}
		case 2: {
			int temp_choice = 0;
			std::cout << "What vector:\n\t1: AB\n\t2: CD\n";
			std::cin >> temp_choice;
			switch (temp_choice) {
			case 1: {
				Coord = print_interface(1);
				AB.set_A(Coord[0], Coord[1], Coord[2]);
				AB.set_B(Coord[3], Coord[4], Coord[5]);
				AB.update();
				break;
			}
			case 2: {
				Coord = print_interface(2);
				CD.set_A(Coord[0], Coord[1], Coord[2]);
				CD.set_B(Coord[3], Coord[4], Coord[5]);
				CD.update();
				break;
			}
			default: {
				error();///
				break;
			}
			}
			break;
		}
		case 3: {
			std::cout << "Angle bettween vectors = " << AB.angle_degree(CD) << " (degree) or " << AB.angle_radian(CD) << "(radian)."<< std::endl;
			break;
		}
		case 4: {
			int temp_choice = 0;
			std::cout << "What vector:\n\t1: AB\n\t2: CD\n";
			std::cin >> temp_choice;
			switch (temp_choice) {
			case 1: {
				std::cout << "Module of vector AB = " << AB.module() << std::endl;
				break;
			}
			case 2: {
				std::cout << "Module of vector CD = " << CD.module() << std::endl;
				break;
			}
			default: {
				error();
				break;
			}
			}
			break;
		}
		case 5: {
			std::cout << "The scalar product of vectors = " << AB.multiply(CD) << std::endl;
			break;
		}
		case 6: {
			vector_in_3d& ab = AB;
			vector_in_3d& cd = CD;
			print_all_data(ab, cd);
			break;
		}
		case 7: {
			quit = 1;
			break;
		}
		default: {
			error();///////
			break;
		}
		}
		system("PAUSE");
		system("cls");
	} while (quit == 0);
}
double* print_interface(int number_of_vector) {
	static std::string name;
	if (number_of_vector == 1) {
		name = "AB";
	}
	else if (number_of_vector == 2) {
		name = "CD";
	}
	std::cout << "Give param of vector " << name << ":\nCoordinate of first Point:\n\tx: ";
	double x1;
	double y1;
	double z1;
	std::cin >> x1;
	std::cout << "\ty: ";
	std::cin >> y1;
	std::cout << "\tz: ";
	std::cin >> z1;
	std::cout << "Coordinate of second Point:\n\tx: ";
	double x2;
	double y2;
	double z2;
	std::cin >> x2;
	std::cout << "\ty: ";
	std::cin >> y2;
	std::cout << "\tz: ";
	std::cin >> z2;
	static double Coordinate[6]{};
	Coordinate[0] = x1;
	Coordinate[1] = y1;
	Coordinate[2] = z1;
	Coordinate[3] = x2;
	Coordinate[4] = y2;
	Coordinate[5] = z2;
	double* Arr_with_coord = &(Coordinate[0]);
	return Arr_with_coord;
}
void error() {
	std::cout << "There is no such option.\n";
	return;
}