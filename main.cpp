#include <fstream>
#include "Cube.h"
#include "Cuboid.h"

int main (){

    Cube Cube1;
    Cube Cube2(2, 2, 2, 6, 6, 6);
    Cube Cube3;
    Cuboid Cuboid1;
    Cuboid Cuboid2;
    Cuboid Cuboid3;
    

    ifstream file_in("./test_data.txt");
    ofstream file_out("./answer.txt", ios::app);
    
    file_in >> Cube1 >> Cuboid1 >> Cuboid2;

    Cuboid Cuboid4(Cuboid2);

    Cube1.shift(1, 1);
    Cube2.rotate(0, 1);

    Cuboid1.shift(-1, 2);
    Cuboid1.shift(-2, 2);
    Cuboid1.shift(-3, 2);

    Cube3.setpoint(0, 0, 0, 8, 8, 8);
    Cuboid3.setpoint(4, 4, 4, 10, 7, 10);
    
    ////////////////////////////////////////////////////////
    /* test 1 */
    file_out << "\n\n";
    file_out << "1. Cube1(x1, y1, z1, x2, y2, z2) = Cube1( " << Cube1.x1 << ", " << Cube1.y1 << ", " << Cube1.z1 << ", " << Cube1.x2 << ", " << Cube1.y2 << ", " << Cube1.z2 << " )" << endl;
    file_out << "2. Cube2(x1, y1, z1, x2, y2, z2) = Cube2( " << Cube2.x1 << ", " << Cube2.y1 << ", " << Cube2.z1 << ", " << Cube2.x2 << ", " << Cube2.y2 << ", " << Cube2.z2 << " )" << endl;
    file_out << "3. Volume of interference part is: ";
    file_out << Cube1.interVolumn(Cube2.x1, Cube2.y1, Cube2.z1, Cube2.x2, Cube2.y2, Cube2.z2) << endl;
    file_out << "4. Cube2 volumn after shrink : " << Cube2 / 8 << "\n";
    file_out << "5. Two diagnol coordinates of Cube2 :\n" << Cube2;

    ////////////////////////////////////////////////////////
    /* test 2 */
    file_out << "\n\n";
    file_out << "6. Cuboid1(x1, y1, z1, x2, y2, z2) = Cuboid1( " << Cuboid1.x1 << ", " << Cuboid1.y1 << ", " << Cuboid1.z1 << ", " << Cuboid1.x2 << ", " << Cuboid1.y2 << ", " << Cuboid1.z2 << " )" << endl;
    file_out << "7. Cuboid4(x1, y1, z1, x2, y2, z2) = Cuboid4( " << Cuboid4.x1 << ", " << Cuboid4.y1 << ", " << Cuboid4.z1 << ", " << Cuboid4.x2 << ", " << Cuboid4.y2 << ", " << Cuboid4.z2 << " )" << endl;
    file_out << "8. Volume of interference part is: ";
    file_out << Cuboid1.interVolumn(Cuboid4.x1, Cuboid4.y1, Cuboid4.z1, Cuboid4.x2, Cuboid4.y2, Cuboid4.z2) << endl;
    file_out << "9. Cuboid4 volumn after shrink : " << Cuboid4 / 8 << endl;
    file_out << "10. Two diagnol coordinates of Cuboid4 :\n" << Cuboid4;

    ////////////////////////////////////////////////////////
    /* test 3 */
    file_out << "\n\n";
    file_out << "11. Cube3(x1, y1, z1, x2, y2, z2) = Cube3( " << Cube3.x1 << ", " << Cube3.y1 << ", " << Cube3.z1 << ", " << Cube3.x2 << ", " << Cube3.y2 << ", " << Cube3.z2 << " )" << endl;
    file_out << "12. Cuboid3(x1, y1, z1, x2, y2, z2) = Cuboid3( " << Cuboid3.x1 << ", " << Cuboid3.y1 << ", " << Cuboid3.z1 << ", " << Cuboid3.x2 << ", " << Cuboid3.y2 << ", " << Cuboid3.z2 << " )" << endl;
    file_out << "13. Volume of interference part is: ";
    file_out << Cuboid3.interVolumn(Cube3.x1, Cube3.y1, Cube3.z1, Cube3.x2, Cube3.y2, Cube3.z2) << endl;
    file_out << "14. Cuboid3 volumn after shrink : " << Cuboid3 / 2 << endl;
    file_out << "15. Two diagnol coordinates of Cuboid3 :\n" << Cuboid3;
    file_out << "16. Cuboid3 volumn after enlarge : " << Cuboid3 *3.14 << endl;
    file_out << "17. Two diagnol coordinates of Cuboid3 :\n" << Cuboid3;
    file_out.close();

    return 0;
}