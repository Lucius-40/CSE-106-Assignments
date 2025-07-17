#include <bits/stdc++.h>

using namespace std;

class Course
{
    string name;
    float credit;

public:
    Course()
    {
        name = "";
        credit = 0;
    }
    Course(string name, float creditHour)
    {
        this->name = name;
        credit = creditHour;
    }

    string getName() { return name; }
    float getCreditHour() { return credit; }
    void setName(string s) { name = s; }
    void setCreditHour(float creditHour) { credit = creditHour; }

    void display()
    {
        cout << "Course Name : " << name << " , Credit Hour : " << credit;
    }
};

class Student
{
    string name;
    int id;
    Course *courses;
    int total;
    int max;
    float *grades;

public:
    Student()
    {
        name = "";
        id = 0;
        total = 0;
        max = 10;
        courses = new Course[10];
        grades = new float[10];
    }
    Student(string name, int id, int maxCourses)
    {
        this->name = name;
        this->id = id;
        total = 0;
        max = maxCourses;
        courses = new Course[max];
        grades = new float[max];
    }
    Student(const Student &ob)
    {
        name = ob.name;
        id = ob.id;
        total = ob.total;
        max = ob.max;
        courses = new Course[max];
        grades = new float[max];
        for (int i = 0; i < total; i++)
        {
            courses[i] = ob.courses[i];
            grades[i] = ob.grades[i];
        }
    }
    // Student &operator=(const Student &ob)
    // {
    //     if (this == &ob)
    //         return *this;
    //     name = ob.name;
    //     id = ob.id;
    //     total = ob.total;
    //     max = ob.max;
    //     courses = new Course[max];
    //     grades = new float[max];
    //     for (int i = 0; i < total; i++)
    //     {
    //         courses[i] = ob.courses[i];
    //         grades[i] = ob.grades[i];
    //     }
    //     return *this;
    // }
    ~Student()
    {
        delete[] courses;
        delete[] grades;
    }

    void setName(string s) { name = s; }
    void setId(int d) { id = d; }
    void setInfo(string s, int d)
    {
        name = s;
        id = d;
    }

    void addCourse(Course c)
    {
        if (total == max)
        {
            cout << "Cannot add more courses to " << name << endl;
            return;
        }
        for (int i = 0; i < total; i++)
        {
            if (c.getName() == courses[i].getName())
            {
                cout << "Course already added \n"
                     << endl;
                return;
            }
        }
        courses[total] = c;
        grades[total] = 0;
        total++;
    }

    void addCourse(Course course, float gradePoint)
    {
        if (total == max)
        {
            cout << "Cannot add more courses to " << name << endl;
            return;
        }
        for (int i = 0; i < total; i++)
        {
            if (course.getName() == courses[i].getName())
            {
                cout << "Course already added \n"
                     << endl;
                return;
            }
        }
        courses[total] = course;
        grades[total] = gradePoint;
        total++;
    }

    void setGradePoint(Course c, float gradePoint)
    {
        if (gradePoint > 4.0 and gradePoint < 0)
        {
            cout << "Invalid grade \n";
            return;
        }
        for (int i = 0; i < total; i++)
        {
            if (courses[i].getName() == c.getName() and courses[i].getCreditHour() == c.getCreditHour())
            {
                grades[i] = gradePoint;
            }
        }
    }
    void setGradePoint(float *gradePoints, int n)
    {
        if (n > total)
        {
            cout << "Not enough courses \n";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (gradePoints[i] > 4.0 and gradePoints[i] < 0)
                cout << "Invalid grade \n";
            else
                grades[i] = gradePoints[i];
        }
    }

    string getName() { return name; }

    float getCGPA()
    {
        float cg = 0, tcredit = 0;
        for (int i = 0; i < total; i++)
        {
            tcredit += courses[i].getCreditHour();
            cg += (grades[i] * courses[i].getCreditHour());
        }
        cg = cg / tcredit;
        return cg;
    }

    float getGradePoint(Course c)
    {
        for (int i = 0; i < total; i++)
        {
            if (courses[i].getName() == c.getName() and courses[i].getCreditHour() == c.getCreditHour())
            {
                return grades[i];
            }
        }
        //cout << "Course not enrolled in \n";
        return -1;
    }

    int getTotalCourses() { return total; }

    float getTotalCreditHours()
    {
        float f = 0;
        for (int i = 0; i < total; i++)
        {
            if (grades[i] >= 2)
                f += courses[i].getCreditHour();
        }
        return f;
    }

    Course getMostFavoriteCourse()
    {
        if (total == 0)
        {
            cout << "No courses Enrolled in\n";
        }
        float res = grades[0];
        int target = 0;
        for (int i = 0; i < total; i++)
        {
            if (grades[i] > res)
            {
                res = grades[i];
                target = i;
            }
        }
        return courses[target];
    }

    Course getLeastFavoriteCourse()
    {
        if (total == 0)
        {
            cout << "No courses Enrolled in\n";
        }
        float res = grades[0];
        int target = 0;
        for (int i = 0; i < total; i++)
        {
            if (grades[i] < res)
            {
                res = grades[i];
                target = i;
            }
        }
        return courses[target];
    }

    Course *getFailedCourses(int &count)
    {
        count = 0;
        int n = 0;

        for (int i = 0; i < total; i++)
        {
            if (grades[i] < 2.0)
                count++;
        }
        Course *c = new Course[count];
        for (int i = 0; i < total; i++)
        {
            if (grades[i] < 2.0)
            {
                c[n] = courses[i];
                n++;
            }
        }
        return c;
    }
    void display()
    {
        cout << "==================================" << endl;
        cout << "Student name : " << name << " ID : " << id << endl;
        for (int i = 0; i < total; i++)
        {
            courses[i].display();
            cout << " , Gradepoint : " << grades[i] << endl;
        }
        cout << "CGPA : " << getCGPA() << endl;
        cout << "Total Credit Hours Earned : " << getTotalCreditHours() << endl;
        cout << "Most Favorite Subject : " << getMostFavoriteCourse().getName() << endl;
        cout << "LEast Favorite Subject: " << getLeastFavoriteCourse().getName()<<endl ;
        cout << "==================================" << endl;
    }
};

int totalStudents = 0;
Student *students[100];

Student getTopper()
{
    float f = students[0]->getCGPA();
    int target = 0;
    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i]->getCGPA() > f)
        {
            f = students[i]->getCGPA();
            target = i;
        }
    }
    return *(students[target]);
}
Student getTopper(Course c)
{

   
    float f = students[0]->getGradePoint(c);
    int target = 0;
    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i]->getGradePoint(c) > f)
        {
            f = students[i]->getGradePoint(c);
            target = i;
        }
    }

    return *(students[target]);
}

int main()
{
    // generate courses
    const int COURSE_COUNT = 6;
    Course courses[COURSE_COUNT] = {
        Course("CSE107", 3),
        Course("CSE105", 3),
        Course("CSE108", 1.5),
        Course("CSE106", 1.5),
        Course("EEE164", 0.75),
        Course("ME174", 0.75),
    };
    float gradePoints[COURSE_COUNT] = {4.0, 4.0, 3.5, 3.5, 4.0, 3.25};
    // generate students
    Student s1 = Student("Sheldon", 1, 5);
    students[totalStudents++] = &s1;
    // add courses to s1
    s1.addCourse(courses[0]);
    s1.addCourse(courses[1]);
    s1.addCourse(courses[2]);
    s1.addCourse(courses[3]);
    s1.addCourse(courses[4]);
    s1.addCourse(courses[5]);
    s1.setGradePoint(gradePoints, s1.getTotalCourses());
    s1.display();
    Student s2 = Student("Penny", 2, 5);
    students[totalStudents++] = &s2;
    s2.addCourse(courses[0]);
    s2.addCourse(courses[2]);
    s2.addCourse(courses[5]);
    s2.setGradePoint(gradePoints, s2.getTotalCourses());
    s2.setGradePoint(courses[0], 3.25);
    s2.display();
    // eikhane bug thakte pare
    Student s3 = s2;
    students[totalStudents++] = &s3;
    s3.setId(3);
    s3.setGradePoint(gradePoints, s3.getTotalCourses());
    s3.setName("Leonard");
    s3.addCourse(courses[1], 3.75); // bug here
    // cout << "Spot 1"<<endl ;
    // cout << "Spot 2"<<endl ;
    s3.display();
    Student s4 = s3;
    students[totalStudents++] = &s4;
    s4.setInfo("Howard", 4);
    s4.setGradePoint(gradePoints, s4.getTotalCourses());
    s4.addCourse(courses[3], 3.75);
    s4.display();
    Student s5 = s4;
    // cout << "Spot 3"<<endl ;
    students[totalStudents++] = &s5;
    s5.setInfo("Raj", 5);
    s5.setGradePoint(gradePoints, s5.getTotalCourses());
    s5.setGradePoint(courses[0], 1.5);
    s5.setGradePoint(courses[2], 2.0);
    s5.setGradePoint(courses[5], 1.75);
    s5.setGradePoint(courses[3], 3.75);
    s5.display();
    // cout << "Spot 4"<<endl ;

    int failedCount;
    Course *failedCourses = s5.getFailedCourses(failedCount); // bug  here
    // cout << "Spot 1 "<< endl ;
    cout << "Failed Courses for " << s5.getName() << ":" << endl;
    for (int i = 0; i < failedCount; ++i)
    {
        failedCourses[i].display();
        cout << endl;
    }
    delete[] failedCourses;
    cout << "==================================" << endl;
    Student topper = getTopper();
    cout << "Topper: " << topper.getName() << endl;
    cout << "Topper CGPA: " << topper.getCGPA() << endl;
    cout << "==================================" << endl;
    for (int i = 0; i < COURSE_COUNT; ++i)
    {
        Course c = courses[i];
        Student topperInCourse = getTopper(c);
        cout << "Topper in " << c.getName() << ": " << topperInCourse.getName() << endl;
        cout << "Topper in " << c.getName() << " gradePoint: " << topperInCourse.getGradePoint(c) << endl;
        cout << "==================================" << endl;
    }
    return 0;
}
