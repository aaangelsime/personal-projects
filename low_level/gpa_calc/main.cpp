#include <iostream>
#include <array>
#include <vector>

int main (int argc, char* argv[])
{
    int num_classes;
    std::vector<char> semester_grades(num_classes);
    
    std::cout << "\n  ========================\n";
    std::cout << "  ==== GPA CALCULATOR ====\n";
    std::cout << "  ========================\n";
    
    std::cout << "\nEnter the number of classes taken this semester: ";
    std::cin >> num_classes;

    int n_classes = num_classes;
    std::vector<float> s_grades(n_classes);
    
    for (int i = 0; i < num_classes; ++i)
    {
        std::cout << "Enter grade for class " << i + 1 << "; ";
        std::cin >> semester_grades[i];
    }

    std::cout << "\n======Semester Overlook======\n";

    for (int i = 0; i < num_classes; ++i)
    {
        std::cout << "     Class " << i + 1 << " | Grade = " << semester_grades[i] << std::endl;
    }

    for (int i = 0; i < n_classes; ++i)
    {
        if (semester_grades[i] == 'a')
        {
            s_grades[i] = 4.0;
        }
        else if (semester_grades[i] == 'b')
        {
            s_grades[i] = 3.0;
        }
        else if (semester_grades[i] == 'c')
        {
            s_grades[i] = 2.0;
        }
        else 
        {
            s_grades[i] = 1.0;
        }
    }

    float semester_gpa;

    for (int i = 0; i < n_classes; ++i)
    {
        semester_gpa = semester_gpa + s_grades[i];
    }

    semester_gpa = semester_gpa / n_classes;
    
    std::cout << "\n     Semester GPA: " << semester_gpa << std::endl;

    return 0;
}

