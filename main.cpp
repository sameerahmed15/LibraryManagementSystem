#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Book 
{
  public:
  string bookname;
  string author;
  string publisher;
  int publishYear;
  int isbn;
  Book* next;
 
  ~Book() { }
};

class List{
  Book* head;
  Book* last;

  public:
  List()
  {
    head=NULL;
    last=NULL;
  }


  // Function Prototypes
  void addBook();
  void print_list();
  void delete_list();

  ~List() { }

}; 

int main() 
{ 
  Book B1;
  List L1;
  char a;
  while(true){
  cout<<"Press required option: "<<endl;
  cout<<"To Add Book detail        [A]"<<endl;
  cout<<"To Print Book details     [P]"<<endl;
  cout<<"To Delete Book details    [D]"<<endl;
  cout<<"To Quit                   [Q]"<<endl;
  cin>>a;
  a=toupper(a);
  switch(a)
  {
    case 'A':
    L1.addBook();
    break;

    case 'P':
    L1.print_list();
    break;

    case 'D':
    L1.delete_list();
    break;

    case 'Q':
    break;

    default:
    cout<<"INVALID ENTRY!!"<<endl;
  }
 }
}

void List::addBook()
{
  if(head==NULL)
  {
    Book* temp= new Book;
    cout<<"Enter Book Name: ";
    cin>>temp->bookname;
    cout<<"Enter the Book Author's Name: ";
    cin>>temp->author;
    cout<<"Enter Publisher: ";
    cin>>temp->publisher;
    cout<<"Enter Publish Year: ";
    cin>>temp->publishYear;
    cout<<"Enter ISBN Number: ";
    cin>>temp->isbn;
    temp->next=NULL;
    head=temp;
    last=temp;
  }
  else 
  {
    Book* temp1= new Book;
    cout<<"Enter Book Name: ";
    cin>>temp1->bookname;
    cout<<"Enter the Book Author's Name: ";
    cin>>temp1->author;
    cout<<"Enter Publisher: ";
    cin>>temp1->publisher;
    cout<<"Enter Publish Year: ";
    cin>>temp1->publishYear;
    cout<<"Enter ISBN Number: ";
    cin>>temp1->isbn;
    temp1->next=NULL;
    last->next=temp1;
    last=temp1;

  }

}
void List::print_list()
{
  Book* next_ptr=head;
  if (next_ptr == NULL)
  {
    cout << " Empty List" << endl;
  }
  else {
    while (next_ptr != NULL) {
      cout <<"Book Name: "<<next_ptr->bookname << endl;
      cout <<"Author: "<< next_ptr->author<<endl;
      cout <<"Publisher: "<<next_ptr->publisher<<endl;
      cout <<"Publish Year: "<< next_ptr->publishYear<<endl;
      cout <<"ISBN Number: " <<next_ptr->isbn<<endl<<endl;
      next_ptr = next_ptr->next;
    }
  }

}
void List::delete_list()
{
    Book* ptr1=head;
    Book* ptr2=ptr1->next;
    
    int choice, flag=0;
    cout<<"Enter the isbn number of book detail to be deleted: ";
    cin>>choice;

    if(ptr1->isbn==choice)
    {
        ptr2=ptr2->next;
        head = head->next;
        delete ptr1;
        flag = 1;

    }
    
    while(ptr2->isbn != choice && flag == 0)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
      if(ptr2->isbn == choice)
      {
        
        ptr1->next=ptr2->next;
        delete ptr2;
      }
}
