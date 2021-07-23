//OOPS with C++ Project
//Sub Code: CS4C03 Lab
//Faculty: Dr Phaneendra, Hema Pandith and Prameela M
//Student: Adeep Krishna Keelar
//Project: Tool Kit
#undef UNICODE
#define UNICODE
#include<iostream>
#include<iomanip>
#include<math.h>
#include<ctime>
#include<algorithm>
#include<vector>
#include<string>
#include<unistd.h>
#include<windows.h>  //for the WinAPI part
using namespace std;

class base_details {
private:
  string name,pass;
  int options;
public:
  void login_entry() {
    do {
    cout<<"\n\n\t Enter the name: "; cin>>name;
    cout<<"\n\t Enter the password: "; cin>>pass;
    if(pass=="adeep") {
      cout<<"\t Login Successful";
      sleep(3);
      system("cls");
      break;
    }
    else {
      cout<<"\t Not possible! Try again";
      sleep(3);
      system("cls");
    }
  }while(true);
 }

   int choicee() {
     cout<<"\t Tool Box ";
     cout<<"\nThere are many tools you can choose: "<<endl;
     cout<<"1.Calculator \n2.Converter \n3.Matrix Calculator \n4.Set Calculator \n5.Shape Calculator \n6.Date and Time provider \n7.Acknowledgement \n8.CGPA Calculator";
     cin>>options;
     return options;
   }
};

//template class for the calculator
template <class var>
class Calculator {
public:
     var n1,n2;
     char op;

    Calculator() {
        n1=n2=0;
      }

      void calculate_numbers() {
        cout<<"Enter the first number: "; cin>>n1;
        cout<<"\nEnter the second number: "; cin>>n2;
        cout<<"\nEnter the operation you need to perform: "; cin>>op;
        switch(op) {
          case '+': cout<<n1<<" "<<op<<" "<<n2<<" = "<<n1+n2<<endl; break;
          case '-': cout<<n1<<" "<<op<<" "<<n2<<" = "<<n1-n2<<endl; break;
          case '*': cout<<n1<<" "<<op<<" "<<n2<<" = "<<n1*n2<<endl; break;
          case '/': cout<<n1<<" "<<op<<" "<<n2<<" = "<<n1/n2<<endl; break;
          default: cout<<"Invalid option!";
        }
      }
};

//converter uses basic classes and inside class definition
//distance, height, weight, money - dollar, pound, yen and euro and BMI
//temperature to be added soon
class Converter {
private:
    int choice;
public:
     Converter() {
       choice=0;
     }

     void converter_func() {
       cout<<"Which converter tool do you want to use?";
       cout<<"\n1.Distance \n2.Height \n3.Weight \n4.Money \n5.BMI Converter";
       cin>>choice;
     }

     void converter_func_dist() {
       float dis;
       cout<<"Enter the distance in cms: ";
       cin>>dis;
       cout<<dis<<" cms"<<endl;
       cout<<"\tThe table of values --"<<endl;
       cout<<dis<<" cms - "<<(dis/100)<<" meters"<<endl;
       cout<<dis<<" cms - "<<(dis/100000)<<" kilometers"<<endl;
       cout<<dis<<" cms - "<<(dis/30.48)<<" feet"<<endl;
     }

     void converter_func_heig() {
        float height;
        float main_hei,rem_hei;
        cout<<"Enter the height: "; cin>>height;
        cout<<"Height entered is "<<height<<" cms";
        cout<<"\n\t Table of values--"<<endl;
        cout<<"1. "<<height<<" cms = "<<(height/100)<<" meters"<<endl;
        cout<<"2. "<<height<<" cms = "<<(height/30.48)<<" feet"<<endl;
     }

     void converter_func_weig() {
          float weight;
          cout<<"Enter weight in kilograms: "; cin>>weight;
          cout<<"Entered weight is "<<weight<<" kgs"<<endl;
          cout<<"\t Table of Values-- "<<endl;
          cout<<"\t1. "<<weight<<" kgs = "<<(weight*1000)<<" grams"<<endl;
          cout<<"\t2. "<<weight<<" kgs = "<<(weight*2.205)<<" pounds"<<endl;
          cout<<"\t3. "<<weight<<" kgs = "<<(weight/6.35)<<" stone"<<endl;
     }

     void converter_func_mone() {
        int op1;
        float curr;
        cout<<"\t Money Converter ";
        cout<<"\n1. Convert to different currencies \n2.Convert to rupees";
        cin>>op1;
        if(op1==1) {
          cout<<"Enter the amount to be checked: "; cin>>curr;
          cout<<"\n\t Table of Currencies"<<endl;
          cout<<"\t1. Rs "<<curr<<" in US Dollars is $ "<<(curr/74.61)<<endl;
          cout<<"\t2. Rs "<<curr<<" in UK Pounds is £ "<<(curr/102.74)<<endl;
          cout<<"\t3. Rs "<<curr<<" in Japenese Yen is ¥ "<<(curr/0.68)<<endl;
          cout<<"\t4. Rs "<<curr<<" in Euros is € "<<(curr/88.08)<<endl;
        }
        else {
          cout<<"Enter the amount to be checked: "; cin>>curr;
          cout<<"\n\t Table of Currencies"<<endl;
          cout<<"\t1. $ "<<curr<<" is Rs "<<(curr*74.61)<<endl;
          cout<<"\t2. £ "<<curr<<" is Rs "<<(curr*102.74)<<endl;
          cout<<"\t3. ¥ "<<curr<<" is Rs "<<(curr*0.68)<<endl;
          cout<<"\t4. € "<<curr<<" is Rs "<<(curr*88.08)<<endl;
        }
     }

     void converter_func_bmi() {
       float height,weight;
       float bmi;
       cout<<"Enter the height in cms: ";
       cin>>height;
       height/=100;
       cout<<"Enter the weight in kgs: ";
       cin>>weight;
       bmi=weight/(height*height);
       cout<<"Your BMI is "<<bmi<<endl;
       if(bmi<18) { cout<<"You are under-weight"<<endl; }
       else if(bmi>=18 && bmi<=25) { cout<<"You are in right weight"<<endl; }
       else if(bmi>=25 && bmi<=30) { cout<<"You are overweight"<<endl; }
       else { cout<<"You are seriously overweight"<<endl; }
     }

     void converter_func_imp() {
       switch(choice) {
         case 1: converter_func_dist(); break;
         case 2: converter_func_heig(); break;
         case 3: converter_func_weig(); break;
         case 4: converter_func_mone(); break;
         case 5: converter_func_bmi(); break;
         default: cout<<"Invalid choice"<<endl;
       }
     }
};

//this class has mostly system calls
class date_time_view {
private:
public:
   void view_func1() {
     time_t current_time=time(0);
     char *date_view=ctime(&current_time);
     cout<<"The time displayed is: "<<date_view<<endl;
   }
};

//this class stores those functions that work on the concept of operator overloading
//matrix addition, subtraction and Multiplication
//transpose will be added soon
class Matrix_calc {
private:
   int row, column;
   int m[20][20];
 public:
    Matrix_calc() {
      row=column=0;
    }
    void read_mat() {
      cout<<"Enter the row and column value: ";
      cin>>row>>column;
      cout<<"Enter the values of the matrix: ";
      for(int i=0;i<row;i++) {
        for(int j=0;j<column;j++) {
          cin>>m[i][j];
        }
      }
  }

    int operator == (Matrix_calc mat2) {
      if(column== mat2.row) {
        return 1;
      }
      else {
        return 0;
      }
    }

  Matrix_calc operator +(Matrix_calc m2) {
      Matrix_calc temp_mat;
      for(int i=0;i<row;i++) {
        for(int j=0;j<column;j++) {
          temp_mat.m[i][j]=m[i][j]+m2.m[i][j];
        }
        temp_mat.row=row;
        temp_mat.column=column;
      }
      return temp_mat;
    }

    Matrix_calc operator -(Matrix_calc m2) {
        Matrix_calc temp_mat;
        for(int i=0;i<row;i++) {
          for(int j=0;j<column;j++) {
            temp_mat.m[i][j]=m[i][j]-m2.m[i][j];
          }
          temp_mat.row=row;
          temp_mat.column=column;
        }
        return temp_mat;
      }

    Matrix_calc operator *(Matrix_calc m2) {
      Matrix_calc temp_mat;
      for(int i=0;i<row;i++) {
        for(int j=0;j<column;j++) {
          temp_mat.m[i][j]=0;
          for(int k=0;k<column;k++)
            temp_mat.m[i][j]+=m[i][k]*m2.m[k][j];
        }
      }
    }

friend ostream& operator << (ostream &, Matrix_calc &);

};

ostream& operator << (ostream &ost, Matrix_calc &m) {
     for(int i=0;i<m.row;i++) {
       for(int j=0;j<m.column;j++) {
         ost<<m.m[i][j];
         ost<<" ";
       }
       ost<<endl;
     }
     return ost;
}

//This class heavily utilises Vector STL functions
//further scope for other operations using other STL functions
//to be added in future
class Sets {
private:
  int n,m,c;
  int set1[100], set2[100];
public:
  void input() {
    cout<<"Enter the size of the first set: "; cin>>n;
    cout<<"Enter the size of the second set: "; cin>>m;
    cout<<"Enter the elements of the first set: ";
    for(int i=0;i<n;i++) {
      cin>>set1[i];
    }
    cout<<"Enter the elements of the second set: ";
    for(int i=0;i<m;i++) {
      cin>>set2[i];
    }
  }

  void set_operation_union() {
    vector<int> v(10);
    vector<int>::iterator i;
     sort(set1,set1+n);
     sort(set2,set2+m);
     i= set_union(set1,set1+n,set2,set2+m,v.begin());
     v.resize(i-v.begin());
     cout<<"The Union of the sets are: "<<endl;
     cout<<"Number of elements: "<<v.size()<<endl;
     for(i=v.begin();i!=v.end();i++) {
       cout<<*i<<" ";
     }
     cout<<endl;
  }

  void set_operation_intersection() {
    vector<int> v(10);
    vector<int>::iterator i;
    sort(set1,set1+n);
    sort(set2,set2+m);
    i=set_difference(set1,set1+n,set2,set2+m,v.begin());
    v.resize(i-v.begin());
    cout<<"The Intersection of the sets are: "<<endl;
    cout<<"Number of elements: "<<v.size()<<endl;
    for(i=v.begin();i!=v.end();i++) {
      cout<<*i<<" ";
    }
    cout<<endl;
  }

  void set_operation_difference(int arr1[], int n,int arr2[], int m) {
    int res[20], res_size=0, flag=0,choice;
    for(int i=0;i<n;i++) {
      flag=0;
      for(int j=0;j<m;j++) {
        if(arr1[i]==arr2[j]) {
          flag=1;
          break;
        }
      }
        if(flag==0) {
          res[res_size]=arr1[i];
          res_size++;
        }
    }
    print_arr(res,res_size);
  }

  void print_arr(int arr[], int n) {
    for(int i=0;i<n;i++) {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

  void sets_operation_decide() {
    cout<<"Enter which operation you would like to perform: ";
    cout<<"\n1. Sets Union \n2.Sets Intersection \n3.Sets Difference"<<endl;
    cin>>c;
    switch(c) {
      case 1: input(); set_operation_union(); break;
      case 2: input(); set_operation_intersection(); break;
      case 3: input();
              set_operation_difference(set1,n,set2,m);
              set_operation_difference(set2,m,set1,n);
              break;
      default: cout<<"Error!";
    }
  }

};

//basic functions with nearly overloading unachieved.
class shapes_details {
private:
  int c;
  double area,volume,perimeter;
public:
  shapes_details() {
    c=0;
    area=volume=perimeter=0.0;
  }
  void shape_pick() {
    cout<<"Enter the shape you want to check: ";
    cout<<"\n1.Square (Cube) \n2.Rectangle (Cuboid) \n3.Triangle \n4.Cylinder \n5.Circle \n6.Cone";
    cin>>c;
    switch(c) {
      case 1: double s;
              cout<<"Enter the side of the object: ";
              cin>>s;
              shape_pick_square(s);
              break;

      case 2: double l,b,h;
              cout<<"Enter the length, breadth and height of the object: ";
              cin>>l>>b>>h;
              shape_pick_rect(l,b,h);
              break;

      case 3: double s1,s2,s3;
              cout<<"Enter the three sides of the triangle: ";
              cin>>s1>>s2>>s3;
              shape_pick_triangle(s1,s2,s3);
              break;

      case 4: double he,r;
              cout<<"Enter the height and radius of the object: ";
              cin>>he>>r;
              shape_pick_cylinder(he,r);
              break;

      case 5: double ra;
              cout<<"Enter the radius of the object: ";
              cin>>ra;
              shape_pick_circle(ra);
              break;

      case 6: double rad,hei;
              cout<<"Enter the radius and height of the object: ";
              cin>>rad>>hei;
              shape_pick_cone(rad,hei);
              break;

      default: cout<<"Error! Invalid!";
    }
  }

  void shape_pick_square(double s) {
    area=pow(s,2);
    perimeter=4*s;
    volume=pow(s,3);
    cout<<"Area = "<<area<<" sq. units"<<endl;
    cout<<"Perimeter = "<<perimeter<<" units"<<endl;
    cout<<"Volume = "<<volume<<" cubic. units"<<endl;
  }

  void shape_pick_rect(double l,double b,double h) {
    area=l*b;
    perimeter=2*(l+b);
    volume=l*b*h;
    cout<<"Area = "<<area<<" sq. units"<<endl;
    cout<<"Perimeter = "<<perimeter<<" units"<<endl;
    cout<<"Volume = "<<volume<<" cubic. units"<<endl;
  }

  void shape_pick_triangle(double s1,double s2,double s3) {
    double s=(s1+s2+s3)/2;
    area=sqrt((s*(s-s1))*(s*(s-s2))*(s*(s-s3)));
    perimeter=s1+s2+s3;
    volume=area*s;
    cout<<"Area = "<<area<<" sq. units"<<endl;
    cout<<"Perimeter = "<<perimeter<<" units"<<endl;
    cout<<"Volume = "<<volume<<" cubic. units"<<endl;
  }

  void shape_pick_cylinder(double h, double r) {
    double pi=3.142;
    area=2*pi*r*(r+h);
    perimeter=2*pi*r*h;
    volume=pi*pow(r,2)*h;
    cout<<"Area = "<<area<<" sq. units"<<endl;
    cout<<"Perimeter = "<<perimeter<<" units"<<endl;
    cout<<"Volume = "<<volume<<" cubic. units"<<endl;
  }

  void shape_pick_circle(double r) {
    double pi=3.142;
    area=pi*pow(r,2);
    perimeter=2*pi*r;
    volume=(4/3)*pi*pow(r,3);
    cout<<"Area = "<<area<<" sq. units"<<endl;
    cout<<"Perimeter = "<<perimeter<<" units"<<endl;
    cout<<"Volume = "<<volume<<" cubic. units"<<endl;
  }

  void shape_pick_cone(double r, double h) {
    double pi=3.142;
    double l=sqrt(pow(r,2)+pow(h,2));
    area=pi*r*l+pi*r;
    perimeter=pi*r*l;
    volume=(1/3)*pi*pow(r,2)*h;
    cout<<"Area = "<<area<<" sq. units"<<endl;
    cout<<"Perimeter = "<<perimeter<<" units"<<endl;
    cout<<"Volume = "<<volume<<" cubic. units"<<endl;
  }

};

class CGPA_cal {
private:
    int num_sub,total_credit,real_credit;
    int credits[20];
    char subject[20];
    float cgpa;
public:
    CGPA_cal() {
      num_sub=0;
      total_credit=0;
      real_credit=0;
      cgpa=0.0;
    }
    void entry_marks() {
      cout<<"Enter the number of subjects: ";
      cin>>num_sub;
      cout<<"Enter the credits and grade of the subjects: ";
      for(int i=0;i<num_sub;i++) {
        cin>>credits[i]>>subject[i];
      }
      system("cls");
    }
    void calc_score() {
      for(int i=0;i<num_sub;i++) {
        real_credit+=credits[i];
      }
      for(int i=0;i<num_sub;i++) {
        switch(subject[i]) {
          case 'S': total_credit+=credits[i]*10; break;
          case 'A': total_credit+=credits[i]*9; break;
          case 'B': total_credit+=credits[i]*8; break;
          case 'C': total_credit+=credits[i]*7; break;
          case 'D': total_credit+=credits[i]*5; break;
          case 'F': total_credit+=credits[i]*0; break;
          default: cout<<"Error!";
        }
      }
      cout<<"The total credits earned in the semester is: "<<total_credit;
      cgpa=total_credit/real_credit;
      cout<<"\n CGPA of the student: "<<cgpa<<" cgpa"<<endl;
    }
};

//class that hosts the WinAPI MessageBox
class Acknowledgement {
public:
  void thanks() {
    MessageBox(0,L"This was done by Adeep, 4NI19CS007",L"Acknowledgement",MB_SETFOREGROUND);
    MessageBox(0,L"This was OOPS with C++",L"Acknowledgement",MB_SETFOREGROUND);
    MessageBox(0,L"Thanks to Dr Phaneendra, Madam Hema Pandith and Madam Prameela M",L"Acknowledgement",MB_SETFOREGROUND);
    MessageBox(0,L"Thanks to Mrs. Rashmi MR",L"Acknowledgement",MB_SETFOREGROUND);
    MessageBox(0,L"Thanks to NIE",L"Acknowledgement",MB_SETFOREGROUND);
  }
};

//Multiple Inheritance
class derived: public base_details, public Calculator<double>, public Converter, public date_time_view, public Matrix_calc, public Sets, public shapes_details, public Acknowledgement, public CGPA_cal {
};

void main_sub_fun() {
  int c,cc;
  derived d;
  Matrix_calc m1,m2,m3,m4,m5;
  d.login_entry();
  do {
    c=d.choicee();
    switch(c) {
      case 1: d.calculate_numbers(); sleep(5); system("cls"); break;
      case 2: d.converter_func();
              d.converter_func_imp();
              sleep(5);
              break;
      case 3: m1.read_mat();
              m2.read_mat();
              int mc;
              cout<<"Which calculation of Matrix do you want to check? "<<endl;
              cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n"; cin>>mc;
              if(m1 == m2) {
                switch(mc) {
                case 1:  m3=m1+m2; cout<<"\n Matrix Addition results to - "<<endl; cout<<m3<<endl; break;
                case 2:  m4=m1-m2; cout<<"\n Matrix Subtraction results to - "<<endl; cout<<m4<<endl; break;
                case 3:  m5=m1*m2; cout<<"\n Matrix Multiplication results to - "<<endl; cout<<m5<<endl; break;
                default: cout<<"Error!";
              }
            }
              else {
                cout<<"Incompatible matrices!";
              }
              sleep(5);
              break;
      case 4: d.input();
              d.sets_operation_decide();
              sleep(5);
              break;
      case 5: d.shape_pick();
              sleep(5);
              break;
      case 6: d.view_func1();
              sleep(5);
              break;
      case 7: d.thanks();
              sleep(3);
              break;
      case 8: d.entry_marks();
              d.calc_score();
              sleep(3);
      default: cout<<"Error!";
    }
    cout<<"Do you want to check something? Yes or No"; cin>>cc;
  }while(cc!=0);
  cout<<"Thanks for checking my program!";
  cout<<"\n\n\t - By Adeep Krishna Keelar \n\t 4NI19CS007 \n\t 4th Sem A";
}

int main() {
  system("color 3E");
  main_sub_fun();
  return 0;
}
// Program explanation provided in copy
// I bid you good day.
// ------------------------------ X -------------------------------------------------------
