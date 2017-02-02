#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct STUDENT //학생 정보
{
 string name;
 int s_num;
 int ko;
 int en;
 int ma;
 int s_sum;
 float ave;
 STUDENT *next; //다음 학생을 가리치는 포인터
};
struct List {  //List 구조체
    STUDENT* head;
    STUDENT* tail;
};
void InitializeList(List& rlist) //연결 리스트 초기화
{
    rlist.head = new STUDENT;
    rlist.tail = rlist.head;
    rlist.head->s_num = 0;
    rlist.head->next = NULL;
}
void RemoveList(List& rlist)  //연결 리스트의 각 node 삭제
{
  while(rlist.head->next != NULL)
  {
    rlist.tail = rlist.head->next;
    delete rlist.head;
    rlist.head = rlist.tail;
  }  
  delete rlist.head;
}
void Print_Grade(List& rlist) // 성적 출력
{
 STUDENT* pcus; //출력을 위한 STUDENT 포인터
 int average = 0; //전체 학생의 평균
 int sum = 0;
 int count = 0;
 cout << "전체 학생의 성적 입니다. \n";
   cout << "———————————————————————\n";
   cout << "    이 름   국어   영어   수학   총점     평균\n";
   pcus = rlist.head->next;
   while(pcus != NULL)
   {
    cout.width(2);
    cout << pcus->s_num;
    cout.width(7);
    cout << pcus->name;
    cout.width(7);
    cout << pcus->ko;
    cout.width(7);
    cout << pcus->en;
    cout.width(7);
    cout << pcus->ma;
    cout.width(7);
    cout << pcus->s_sum;
    cout.width(9);
    cout << pcus->ave<<endl;
    sum += pcus->ave;
    pcus = pcus->next;
    count++;
   }
   average = sum / count;
   cout << "전체 평균은 " << average << "입니다\n";
   cout << "———————————————————————\n";
}
void Add_Student(List& rlist) //학생 정보 추가
{
 int num; //학생번호 저장
 rlist.tail->next = new STUDENT;
 num = rlist.tail->s_num + 1;  // 다음 학생번호
 rlist.tail = rlist.tail->next;
 rlist.tail->s_num = num;
 cout << "이름: ";
 cin >> rlist.tail->name;
 cout << "국어: ";
 cin >> rlist.tail->ko;
 cout << "영어: ";
 cin >> rlist.tail->en;
 cout << "수학: ";
 cin >> rlist.tail->ma;
 rlist.tail->s_sum = rlist.tail->ko + rlist.tail->en + rlist.tail->ma; //총점 계산
 rlist.tail->ave = (float)rlist.tail->s_sum / 3.0; //평균 계산
 rlist.tail->next = NULL;
}
char Menushow() // 메뉴
{
 system("cls");
  char _select;
  cout<<"——— 메뉴 ———"<<endl;
  cout<<"1. 학생 성적 추가"<<endl;
  cout<<"2. 전체 성적 보기"<<endl;
  cout<<"Q. 프로그램 종료"<<endl;
  cout<<"—————————"<<endl;
  cout<<"원하는 작업의 번호를 입력하세요 : ";
  cin>>_select;
  return _select;
}
int main()
{ 
 char select;
 List list;
 InitializeList(list);
 while(true){
  select = Menushow();
  switch(select)
  {
  case '1'://학생 성적 추가
   Add_Student(list);
   break;
  case '2'://전체 성적 보기
   Print_Grade(list);
   break;
  case 'q'://종료
   cout<<"프로그램을 종료 합니다."<<endl;
   RemoveList(list);
   return 0;
  case 'Q'://종료
   cout<<"프로그램을 종료 합니다."<<endl;
   RemoveList(list);
   return 0;
  default :
    cout << "잘목 입력하셨습니다\n";
  }
  system("pause");
  }
 RemoveList(list);
 return 0;
}
