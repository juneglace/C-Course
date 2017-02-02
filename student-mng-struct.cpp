#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define MAX 3
struct CUSTOMER
{
 string name;
 int s_num;
 int ko;
 int en;
 int ma;
 int s_sum;
 float ave;
};

int main()
{
 CUSTOMER cus[MAX];
 int num = 0; //현재까지 입력된 학생의 수
 int average = 0; //전체 학생의 평균
 int sum = 0;
 while(true){
  system("cls");
  char select;
  cout<<"------ 메뉴 ------"<<endl;
  cout<<"1. 학생 성적 추가"<<endl;
  cout<<"2. 전체 성적 보기"<<endl;
  cout<<"Q. 프로그램 종료"<<endl;
  cout<<"------------------"<<endl;
  cout<<"원하는 작업의 번호를 입력하세요 : ";
  cin>>select;
  switch(select)
  {
  case '1'://학생 성적 추가
   if(num == MAX){
    cout << "더 이상 추가할 수 없습니다.\n";
   }
   else{
    cus[num].s_num = num + 1;
    cout << "이름: ";
    cin >> cus[num].name;
    cout << "국어: ";
    cin >> cus[num].ko;
    cout << "영어: ";
    cin >> cus[num].en;
    cout << "수학: ";
    cin >> cus[num].ma;
    cus[num].s_sum = cus[num].ko + cus[num].en + cus[num].ma; //총점 계산
    cus[num].ave = (float)cus[num].s_sum / 3.0; //평균 계산
    num++;
   }
   break;
  case '2'://전체 성적 보기
   cout << "전체 학생의 성적 입니다. \n";
   cout << "----------------------------------------------\n";
   cout << "    이 름   국어   영어   수학   총점   평균\n";
   for(int i = 0;i < num; i++)
   {
    cout.width(2);
    cout <<cus[i].s_num;
    cout.width(7);
    cout << cus[i].name;
    cout.width(7);
    cout << cus[i].ko;
    cout.width(7);
    cout << cus[i].en;
    cout.width(7);
    cout << cus[i].ma;
    cout.width(7);
    cout << cus[i].s_sum;
    cout.width(7);
    cout << cus[i].ave<<endl;
   }
   for(int i = 0;i < num; i++)
    sum += cus[i].ave;
   average = sum / num;
   cout << "전체 평균은 " << average << "입니다\n";
   cout << "----------------------------------------------\n";
   break;
  case 'q'://종료
   cout<<"프로그램을 종료 합니다."<<endl;
   return 0;
  case 'Q'://종료
   cout<<"프로그램을 종료 합니다."<<endl;
   return 0;
  default :
    cout << "잘목 입력하셨습니다\n";
  }
  system("pause");
  }
 return 0;
}
