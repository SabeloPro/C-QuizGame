#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
#include<windows.h>
using namespace std;


char guess;
int total;
double tTotal,mTotal;



HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


class Questions{

private:
    string Question_text;
    string a;
    string b;
    string c;
    string d;
    string True;
    string False;

public:
    char correct_answer;
    Questions(string,string,string,char);
    Questions(string,string,string,string,string,char);
    void trueOrFalse();
    void askQuestions();
    void shufle(vector<Questions> vec);
    void Instructions();
    void fillVec(vector<Questions>);




};

static void changeFont(int n)
    {
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 0;                   // Width of each character in the font
        cfi.dwFontSize.Y = n;                  // Height
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
        std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }
int main()
{
    changeFont(25);
    Questions *q = new Questions("System Study involves","study of an existing system","study of an existing system","identifying current deficiencies and establishing new goals","All of the above",'d');
    Questions *q1 = new Questions("The primary tool used in structured design is a:","structure chart","data-flow diagram","program flowchart","module",'a');
    Questions *q2 = new Questions("In Prototyping","BASIC is used","COBOL is used","4GLs are used","system is documented",'c');
    Questions *q3= new Questions("The primary tool used in structured design is a:","data-flow diagram","module","structure chart","program flowchart",'c');
    Questions *q4 = new Questions("Documentation is prepared","at every stage","at system design","at system analysis","at system development",'a');
    Questions *q5 = new Questions("The two classifications of inputs are","energies and maintenance","maintenance and waste","maintenance and signal","products and waste",'c');
    Questions *q6= new Questions("System Implementation Phase entails","System check outs","Pilot run","Parallel runs","All of the above",'a');
    Questions *q7 = new Questions("Decision tree uses","pictorial depictation of alternate conditions","nodes and branches","consequences of various depicted alternates","All of the above",'d');
    Questions *q8 = new Questions("An example of a hierarchical data structure is","array","link list","tree","All of the above",'c');
    Questions *q9 = new Questions("Which are the tools not used for System Analysis","System - test data","Decision table","Data Flow Diagram","Flowcharts",'a');

    Questions *t1 = new Questions("Increasingly, organizations adopt and follow a standardized systems development process","True","False",'t');
    Questions *t2 = new Questions("Most information systems meet expectations and come in within budget","True","False",'f');
    Questions *t3 = new Questions("Some organizations develop their own system development methodologies","True","False",'t');
    Questions *t4 = new Questions("The number and scope of phases and activities in a methodology varies","True","False",'t');
    Questions *t5 = new Questions("All life cycle methodologies prescribe phases and activities","True","False",'t');
    Questions *t6 = new Questions("The final phase in most system development methodologies is documentation","True","False",'f');
    Questions *t7 = new Questions("FAST is a leading commercial methodology","True","False",'f');
    Questions *t8 = new Questions("Projects are always planned","True","False",'f');
    Questions *t9 = new Questions("Scope frequently changes during a project","True","False",'t');
    Questions *t0 = new Questions("Scope defines how big the project is or will be","True","False",'t');


    vector<Questions> vec = {*q,*q1,*q2,*q3,*q4};

    vector<Questions>vec1 = {*t1,*t2,*t3,*t4,*t0};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(vec.begin(),vec.end(),std::default_random_engine(seed));
    unsigned seeds = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(vec1.begin(),vec1.end(),std::default_random_engine(seeds));

    q->Instructions();
    system("pause");
    system("cls");
    string n;

    cout<<"You want to start with True or False : Yes/No ";
    cin>>n;
    cout<<"\n";
    system("pause");
    system("cls");
    cout<<"First Level Questions\n\n";
    system("pause");
    system("cls");
if(n == "yes"){

    cout<<"True Or False Questions"<<endl;
    cout<<"________________________"<<endl;
    int i = 1;

    while(i<vec1.size()+1){
            //cout<<endl;
        cout<<"True Or False Question number \t" <<i <<" of "<<5<<"\t Marks :"<<tTotal <<"\n\n"<<endl;
        cout<<i<<". ";
        vec1[i-1].trueOrFalse();
        cout<<"\nYour Answer : ";
        cin>>guess;
        int num = i;
        if(guess=='p'&& i>=1){
            vec1[i-1].trueOrFalse();
            i-=1;
            cout<<"Question number : "<<i<<" "<<endl;
            cout<<"\nYour Answer : ";
            cin>>guess;
            if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct \n\n";

             SetConsoleTextAttribute(h,7);
            tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";

                SetConsoleTextAttribute(h,7);
            }
            i++;
        }
        system("pause");
        system("cls");

        }else if(guess == 'n'&&i<vec1.size()){

            i+=1;
            cout<<"Question number : "<<i<<" "<<endl;
            vec1[i].trueOrFalse();
             cout<<"\nYour Answer : ";
            cin>>guess;
            if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";
                SetConsoleTextAttribute(h,7);
                tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }
        system("pause");
        system("cls");


        }else if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";
                SetConsoleTextAttribute(h,7);
                tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }else{
            cout<<"out of bound try again";

            i = num;

        }
        system("pause");
        system("cls");
    }
    cout<<"\n\n";
     i = 1;

    cout<<"Multple Choice Questions"<<endl;
    cout<<"________________________\n\n"<<endl;
    while(1+vec.size()>i){


        cout<<"Multiple Choice Question number \t " <<i <<" of "<<5<<"\t Marks \t:"<<mTotal <<"\n\n"<<endl;
        cout<<i<<". ";
        vec[i-1].askQuestions();
        cout<<endl;
        cout<<"Your Answer : ";

        cin>>guess;
        int num = i;
        if(guess=='p'&& i>=1){
            cout<<"Question number : "<<i<<" "<<endl;
            vec[i-1].askQuestions();
            i-=1;

            cout<<"Your Answer : ";
            cin>>guess;
            if(guess == 'a'||guess == 'b'||guess == 'c'||guess == 'd'){
             if(guess==vec[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct"<<endl;
            cout<<"\n\n ";
             SetConsoleTextAttribute(h,7);
            mTotal++;


            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer<<endl;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }


        }

        }else if(guess == 'n'&&i<vec.size()){
            system("pause");
            system("cls");
            i++;
            cout<<"Question number : "<<i<<" "<<endl;
            vec[i].askQuestions();
             cout<<"Your Answer : ";
            cin>>guess;
            if(guess == 'a'||guess == 'b'||guess == 'c'||guess == 'd'){
             if(guess==vec[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct \n\n";

             SetConsoleTextAttribute(h,7);
            mTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer<<endl;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }

        }


        }else if(guess == 'd'||guess == 'c'||guess == 'a'||guess == 'b'){
             if(guess==vec[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";

                SetConsoleTextAttribute(h,7);
                mTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }else{
            cout<<"out of bound try again";

            i = num;

        }


        system("pause");
        system("cls");
      }

    int sum = vec1.size()+vec.size();
    double sum2 = tTotal+mTotal;
     total = ((sum2/sum)*100);

    SetConsoleTextAttribute(h,30);




    system("pause");
    system("cls");
    }else{

    int i = 1;
        cout<<endl;
    while(1+vec.size()>i){


        cout<<"Multiple Choice Question number \t " <<i <<" of "<<10<<"\t Marks \t:"<<mTotal <<"\n\n"<<endl;
        cout<<i<<". ";
        vec[i-1].askQuestions();
        cout<<endl;
        cout<<"Your Answer : ";

        cin>>guess;
        int num = i;
        if(guess=='p'&& i>=1){
            cout<<"Question number : "<<i<<" "<<endl;
            vec[i-1].askQuestions();
            i-=1;

            cout<<"Your Answer : ";
            cin>>guess;
            if(guess == 'a'||guess == 'b'||guess == 'c'||guess == 'd'){
             if(guess==vec[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct"<<endl;
            cout<<"\n\n ";
             SetConsoleTextAttribute(h,7);
            mTotal++;


            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer<<endl;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }


        }

        }else if(guess == 'n'&&i<vec.size()){
            system("pause");
            system("cls");
            i++;
            cout<<"Question number : "<<i<<" "<<endl;
            vec[i].askQuestions();
             cout<<"Your Answer : ";
            cin>>guess;
            if(guess == 'a'||guess == 'b'||guess == 'c'||guess == 'd'){
             if(guess==vec[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct \n\n";

             SetConsoleTextAttribute(h,7);
            mTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer<<endl;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }

        }


        }else if(guess == 'd'||guess == 'c'||guess == 'a'||guess == 'b'){
             if(guess==vec[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";

                SetConsoleTextAttribute(h,7);
                mTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }else{
            cout<<"out of bound try again";

            i = num;

        }


        system("pause");
        system("cls");
      }
    cout<<endl;
    cout<<"True Or False Questions"<<endl;
    cout<<"________________________"<<endl;
    i = 1;

    while(i<vec1.size()+1){
            //cout<<endl;
        cout<<"True Or False Question number \t" <<i <<" of "<<5<<"\t Marks :"<<tTotal <<"\n\n"<<endl;
        cout<<i<<". ";
        vec1[i-1].trueOrFalse();
        cout<<"\nYour Answer : ";
        cin>>guess;
        int num = i;
        if(guess=='p'&& i>=1){
            vec1[i-1].trueOrFalse();
            i-=1;
            cout<<"Question number : "<<i<<" "<<endl;
            cout<<"\nYour Answer : ";
            cin>>guess;
            if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct \n\n";

             SetConsoleTextAttribute(h,7);
            tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";

                SetConsoleTextAttribute(h,7);
            }
            i++;
        }
        system("pause");
        system("cls");

        }else if(guess == 'n'&&i<vec1.size()){

            i+=1;
            cout<<"Question number : "<<i<<" "<<endl;
            vec1[i].trueOrFalse();
             cout<<"\nYour Answer : ";
            cin>>guess;
            if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";
                SetConsoleTextAttribute(h,7);
                tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }
        system("pause");
        system("cls");


        }else if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";
                SetConsoleTextAttribute(h,7);
                tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }else{
            cout<<"out of bound try again";

            i = num;

        }
        system("pause");
        system("cls");
    }



    }


     cout<<"-------------------------------\nThe Second Level Of the Quiz Consist of Negative Marking\nDo you wan to proceed yes/No";
     cin>>n;
     int i = 1;
     cout<<endl;
      vec = {*q5,*q6,*q7,*q8,*q9};

    vec1 = {*t5,*t6,*t7,*t8,*t9};

    shuffle(vec.begin(),vec.end(),std::default_random_engine(seed));

    shuffle(vec1.begin(),vec1.end(),std::default_random_engine(seeds));

     if(n == "yes"){

        cout<<"True Or False Questions"<<endl;
    cout<<"________________________"<<endl;
    int i = 1;

    while(i<vec1.size()+1){
            //cout<<endl;
        cout<<"True Or False Question number \t" <<i <<" of "<<5<<"\t Marks :"<<tTotal <<"\n\n"<<endl;
        cout<<i<<". ";
        vec1[i-1].trueOrFalse();
        cout<<"\nYour Answer : ";
        cin>>guess;
        int num = i;
        if(guess=='p'&& i>=1){
            vec1[i-1].trueOrFalse();
            i-=1;
            cout<<"Question number : "<<i<<" "<<endl;
            cout<<"\nYour Answer : ";
            cin>>guess;
            if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct \n\n";

             SetConsoleTextAttribute(h,7);
            tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";

                SetConsoleTextAttribute(h,7);
            }
            i++;
        }
        system("pause");
        system("cls");

        }else if(guess == 'n'&&i<vec1.size()){

            i+=1;
            cout<<"Question number : "<<i<<" "<<endl;
            vec1[i].trueOrFalse();
             cout<<"\nYour Answer : ";
            cin>>guess;
            if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";
                SetConsoleTextAttribute(h,7);
                tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }
        system("pause");
        system("cls");


        }else if(guess == 'f'||guess == 't'){
             if(guess==vec1[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";
                SetConsoleTextAttribute(h,7);
                tTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec1[i-1].correct_answer<<"\n \n";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }else{
            cout<<"out of bound try again";

            i = num;

        }
        system("pause");
        system("cls");
    }
    cout<<"\n\n";
     i = 1;

    cout<<"Multple Choice Questions"<<endl;
    cout<<"________________________\n\n"<<endl;
    while(1+vec.size()>i){


        cout<<"Multiple Choice Question number \t " <<i <<" of "<<5<<"\t Marks \t:"<<mTotal <<"\n\n"<<endl;
        cout<<i<<". ";
        vec[i-1].askQuestions();
        cout<<endl;
        cout<<"Your Answer : ";

        cin>>guess;
        int num = i;
        if(guess=='p'&& i>=1){
            cout<<"Question number : "<<i<<" "<<endl;
            vec[i-1].askQuestions();
            i-=1;

            cout<<"Your Answer : ";
            cin>>guess;
            if(guess == 'a'||guess == 'b'||guess == 'c'||guess == 'd'){
             if(guess==vec[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct"<<endl;
            cout<<"\n\n ";
             SetConsoleTextAttribute(h,7);
            mTotal++;


            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer<<endl;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }


        }
        }else if(guess == 'n'&&i<vec.size()){
            system("pause");
            system("cls");
            i++;
            cout<<"Question number : "<<i<<" "<<endl;
            vec[i].askQuestions();
             cout<<"Your Answer : ";
            cin>>guess;
            if(guess == 'a'||guess == 'b'||guess == 'c'||guess == 'd'){
             if(guess==vec[i-1].correct_answer){
             SetConsoleTextAttribute(h,10);
            cout<<"your answer is correct \n\n";

             SetConsoleTextAttribute(h,7);
            mTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer<<endl;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }

        }


        }else if(guess == 'd'||guess == 'c'||guess == 'a'||guess == 'b'){
             if(guess==vec[i-1].correct_answer){
                SetConsoleTextAttribute(h,10);
                cout<<"your answer is correct\n\n";

                SetConsoleTextAttribute(h,7);
                mTotal++;
            }else{
                SetConsoleTextAttribute(h,12);
                cout<<"wrong answer the correct one is :"<<vec[i-1].correct_answer;
                cout<<"\n\n ";
                SetConsoleTextAttribute(h,7);
            }
            i++;
        }else{
            cout<<"out of bound try again";

            i = num;

        }
        system("pause");
        system("cls");
      }

    int sum = vec1.size()+vec.size();
    double sum2 = tTotal+mTotal;
    total = ((sum2/sum)*100);
    SetConsoleTextAttribute(h,30);
    system("pause");
    system("cls");



     }else{
        cout<<"Terminated";
     }


     system("pause");
        system("cls");
     int sum = vec1.size()+vec.size();
     double sum2 = tTotal+mTotal;
     total = ((sum2/sum)*100);

    SetConsoleTextAttribute(h,30);
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"@  Tue or False Questions : "<<tTotal<<"      @"<<endl;
    cout<<"@  multiple choice question : "<<mTotal<<"    @"<<endl;
    cout<<"@  total is : "<<sum<<"                       @"<<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    SetConsoleTextAttribute(h,7);
    if(total>=50){
            SetConsoleTextAttribute(h,10);
          cout<<"Congratulations you passed "<<total<<endl;
             SetConsoleTextAttribute(h,7);
    }else{
             SetConsoleTextAttribute(h,12);
           cout<<"failed "<<total<<endl;
            SetConsoleTextAttribute(h,7);
    }
     system("pause");
        system("cls");
    SetConsoleTextAttribute(h,20);
    cout<<"MULTIPLE CHOICE THE REVIEW"<<endl;
    SetConsoleTextAttribute(h,7);
    for(int i = 0; i<vec.size();i++){

        cout<<i+1<<". ";
        vec[i].askQuestions();
        cout<<"Correct Answer is :"<<vec[i].correct_answer<<endl;
        cout<<"\n\n";

    }

    system("pause");
    system("cls");

     SetConsoleTextAttribute(h,20);
    cout<<" THE TRUE OR FALSE REVIEW"<<endl;
    SetConsoleTextAttribute(h,7);
    for(int i = 0; i<vec1.size();i++){

        cout<<i+1<<". ";
        vec1[i].trueOrFalse();

        cout<<"Correct Answer is :"<<vec1[i].correct_answer<<endl;
        cout<<"\n\n";
    }
    system("pause");
    system("cls");
    cout<<"\n"<<"The End"<<endl;

    return 0;


}

Questions::Questions(string question,string T,string F,char correct){
    Question_text = question;
    True = T;
    False = F;
    correct_answer = correct;

}



void Questions::trueOrFalse(){
    //cout<<endl;
    cout<<Question_text<<" \n\n";
    cout<<True<<"  "<<False<<endl;

}
 Questions::Questions(string question,string a1,string b1,string c1,string d1,char correct){

    Question_text = question;
    a = a1;
    b = b1;
    c = c1;
    d = d1;
    correct_answer = correct;
}
void Questions::askQuestions(){
    //cout<<endl;
    cout<<Question_text<<" ?"<<endl;
    cout<<endl;
    cout<<"A. "<<a<<endl;
    cout<<"B. "<<b<<endl;
    cout<<"C. "<<c<<endl;
    cout<<"D. "<<d<<endl;


}
void Questions::Instructions(){
    cout<<"\t---------------------------------------------------------"<<endl;
    cout<<"\t|\t SYSTEM ANALYSIS AND DESIGN QUIZ\t\t|"<<endl;
    cout<<"\t|\t INSTRUCTIONS\t\t\t\t\t|"<<endl;
    cout<<"\t|\t 1. Multiple choice questions :\t\t\t|"<<endl;
    cout<<"\t|\t -> Only use letters :\t\t\t\t|"<<endl;
    cout<<"\t|\t -> a for option A\t\t\t\t|"<<endl;
    cout<<"\t|\t -> b for option B\t\t\t\t|"<<endl;
    cout<<"\t|\t -> c for option C\t\t\t\t|"<<endl;
    cout<<"\t|\t -> d for option D\t\t\t\t|"<<endl;
    cout<<"\t|\t -> n to navigate foward\t\t\t|"<<endl;
    cout<<"\t|\t -> p to navigate backwards\t\t\t|"<<endl;
    cout<<"\t|\t -> If you put any key other than the one above |\n\t|\t\t- will remain in the same question\t|"<<endl;
    cout<<"\t---------------------------------------------------------"<<endl;
    cout<<"\t---------------------------------------------------------"<<endl;
    cout<<"\t|\t 2. True\False questions :\t\t\t|"<<endl;
    cout<<"\t|\t -> t for True option\t\t\t\t|"<<endl;
    cout<<"\t|\t -> f for False option\t\t\t\t|"<<endl;
    cout<<"\t|\t -> n to navigate foward\t\t\t|"<<endl;
    cout<<"\t|\t -> p to navigate backwards\t\t\t|"<<endl;
    cout<<"\t|\t -> If you put any key other than the one above |\n\t|\t\t- will remain in the same question\t|"<<endl;
    cout<<"\t---------------------------------------------------------"<<endl<<"\n\n";


}




