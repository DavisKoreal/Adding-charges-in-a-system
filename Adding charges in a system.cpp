#include <iostream>
#include <iomanip>
#include <cmath>
#define EPSILON 8.8541878128*pow(10,-12)
#define PI 3.14159
#define CONSTANT 1/(4*PI*EPSILON)

class Charge {
public:
    double charge;
    double electric_field;
    double x_position;
    double y_position;
    double z_position;
    float x_angle;
    float y_angle;
    float z_angle;
    double len;
    double xelectricfield;
    double yelectricfield;
    double zelectricfield;

    Charge() {
        charge = 0;
        electric_field = 0;
        x_position = 0;
        y_position = 0;
        z_position = 0;
        x_angle = 0;
        y_angle = 0;
        z_angle = 0;
        len = 0;
        xelectricfield = 0;
        yelectricfield = 0;
        zelectricfield = 0;
    }
    Charge(double charg, double x, double y, double z) {
        charge = charg;
        x_position = x;
        y_position = y;
        z_position = z;
        electric_field = findelectricfield();
        x_angle = findx_angle();
        y_angle = findy_angle();
        z_angle = findz_angle();
        len = getlen();
        xelectricfield = findxelectric();
        yelectricfield = findyelectric();
        zelectricfield = findzelectric();
    }
    double findx_angle() {
        return  atan(y_position / x_position);
    }
    double findy_angle() {
        return atan(x_position / y_position);
    }
    double findz_angle() {
        return atan(z_position / sqrt((pow(y_position, 2) + pow(x_position, 2))));
    }
    double findelectricfield() {
        return ((CONSTANT * charge) / (pow(len, 2)));
    }
    double findxelectric() {
        return (charge * cos(z_angle) * cos(x_angle));
    }
    double findyelectric() {
        return (charge * cos(z_angle) * cos(y_angle));
    }
    double findzelectric() {
        return (charge * sin(z_angle));
    }
    double getlen() {
        return (z_position / (sin(z_angle)));
    }
    friend std::ostream& operator<<(std::ostream& os, const Charge& dt);
};
std::ostream& operator<<(std::ostream& os, const Charge& dt)
{
    std::setprecision(7);
    os << std::right << std::setw(20) << "Lenght from 0: " << std::setw(10) << dt.len << std::endl;
    os << std::right << std::setw(20) << "X position: " << std::setw(10) << dt.x_position << std::endl;
    os << std::right << std::setw(20) << "X Angle: " << std::setw(10) << dt.x_angle << std::endl;
    os << std::right << std::setw(20) << "Y position: " << std::setw(10) << dt.y_position << std::endl;
    os << std::right << std::setw(20) << "Y Angle: " << std::setw(10) << dt.y_angle << std::endl;
    os << std::right << std::setw(20) << "Z position: " << std::setw(10) << dt.z_position << std::endl;
    os << std::right << std::setw(20) << "Z Angle: " << std::setw(10) << dt.z_angle << std::endl;
    os << std::right << std::setw(20) << "Electric Field: " << std::setw(10) << dt.electric_field << std::endl;
    os << std::right << std::setw(20) << "X electric Field: " << std::setw(10) << dt.xelectricfield << std::endl; 
    os << std::right << std::setw(20) << "Y electric Field: " << std::setw(10) << dt.yelectricfield << std::endl;
    os << std::right << std::setw(20) << "Z electric Field: " << std::setw(10) << dt.zelectricfield << std::endl;
    return os;
}

int main() {
    std::cout << "How many charge particles do you want to enter? " << std::endl;
    int no_of_particles;
    std::cin >> no_of_particles;
    int counter(1);
    double totalxcharge(0);
    double totalycharge(0);
    double totalzcharge(0);

    while (counter <= no_of_particles) {
        std::cout << "Please input the charge of the particle number " << counter << " in nanofarads."<<std::endl;
        double q;
        std::cin >> q;
        std::cout << "Please put in the x co-ordinate of your particle number " << counter << "." << std::endl;
        double xcod;
        std::cin >> xcod;
        std::cout << "Please put in the y co-ordinate of your particle number " << counter << "." << std::endl;
        double ycod;
        std::cin >> ycod;
        std::cout << "Please put in the z co-ordinate of your particle number " << counter << "." << std::endl;
        double zcod;
        std::cin >> zcod;
        Charge temp(q, xcod, ycod, zcod);
        std::cout << temp << std::endl << std::endl;
        totalxcharge += temp.xelectricfield;
        totalycharge += temp.yelectricfield;
        totalzcharge += temp.zelectricfield;
        counter++;
    }
    double totalelectricfield = sqrt((pow(totalxcharge, 2)) + (pow(totalycharge, 2)) + (pow(totalzcharge, 2)));
    std::cout << "The total resultant electric field of this system is " << totalelectricfield << std::endl;
}