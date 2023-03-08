#include <iostream>
#include <stdlib.h>
#include "dictionarylist.cpp"

using namespace std;

int main() {

cout<<"--------Creating list A key int info string--------"<<endl;
list<int,string> A; 
A.push_back(3,"third");
A.push_back(4,"forth"); 
A.push_front(2,"Second");
A.push_front(1,"First");
A.print();

cout<<"--------Adding key that is not unique--------"<<endl;
A.push_front(2,"Second");
A.push_back(4,"forth");
A.print();

cout<<"-------Deleting content from the back---------"<<endl;
A.pop_back();
A.pop_back();
A.print();

cout<<"-------Deleting content from the front---------"<<endl;
A.pop_front();
A.print();

cout<<"-------When list is empty---------"<<endl;
A.pop_front();
A.print();
cout<< endl;

cout<<"-------Deleting content from empty list---------"<<endl;
A.pop_back();
A.pop_back();
A.print();
cout<< endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

cout<<"-------Creating list B key string info int---------"<<endl;
list<string,int> B; 
B.push_back("first",1);
B.push_back("second",2);
B.print();

cout<<"-------Removing by key---------"<<endl;
B.remove_by_key("second");
B.print();

cout<<"-------Removing by key when key doesn't exist---------"<<endl;
B.remove_by_key("second");
B.print();

cout<<"-------Clearing the list---------"<<endl;
B.clear();
B.print();

cout<<"-------Operations on empty list---------"<<endl;
B.remove_by_key("second");
B.remove_by_key("third");
B.pop_back();
B.pop_back();
B.print();

cout<<"-------Checking if adding still works---------"<<endl;
A.push_back(3,"third");
A.push_back(4,"forth"); 
A.push_front(2,"Second");
A.push_front(1,"First");
A.print();

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

cout<<"-------Creating list C key int info string---------"<<endl;
list<int,string> C;
C.push_back(6,"sixth");
C.push_back(5,"fifth"); 
C.push_front(3,"2third2");
C.push_front(4,"2forth2");
C.print();

cout<<"-------Creating list D key int info string---------"<<endl;
list<int,string> D;
D.push_back(9,"ninth");
D.push_back(10,"tenth"); 
D.push_front(7,"seventh");
D.push_front(8,"eighth");
D.print();

cout<<"-------Copying list C to D (D = C -> print list C)---------"<<endl;
D = C;
C.print();

cout<<"-------Comparing C to D---------"<<endl;
if(C == D) {
 cout<<"lists are the same"<<endl;   
}
else {
  cout<<"lists are different"<<endl;   
}
cout<<endl;

cout<<"-------Comparing C to A---------"<<endl;
if(C==A) {
 cout<<"lists are the same"<<endl;   
}
else {
  cout<<"lists are different"<<endl;   
}
cout<<endl;

cout<<"-------Adding two lists together (C+A)---------"<<endl;
list<int,string> E;
E=C+A;
cout<<endl;

cout<<"List A after"<<endl;
A.print();

cout<<"List C after"<<endl;
C.print();

cout<<"List E after"<<endl;
E.print();

cout<<"-------Joining two lists---------"<<endl;
list<int,string> H;
cout<<"List C before join"<<endl;
C.print();

H.join(C,A);
cout<<"List C after"<<endl;
C.print();

cout<<"List A after"<<endl;
A.print();

cout<<"List H after"<<endl;
H.print();

cout<<"-------Searching by key---------"<<endl;
cout<<"Searching list H"<<endl;
H.search_print(3);
cout<<endl;

cout<<"Searching list A"<<endl;
A.search_print(3);
cout<<endl;

cout<<"Searching list C"<<endl;
C.search_print(3);
cout<<endl;

cout<<"-------Searching by key when key doesn't exist---------"<<endl;
C.search_print(2);
cout<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

cout<<"--------Creating dictionary X key int info string--------"<<endl;
dictionary<int,string> X;
X.add(1,"first");
X.add(2,"second");
X.add(3,"third");
X.add(4,"forth");
X.add(5,"fifth");
X.print();

cout<<"--------Added key that is not unique--------"<<endl;
X.add(1,"first");
X.print();

cout<<"-------Removing by key---------"<<endl;
X.remove_by_key(5);
X.print();

cout<<"-------Removing by key when key doesn't exist---------"<<endl;
X.remove_by_key(5);
X.print();

cout<<"--------Creating dictionary Y key int info string--------"<<endl;
dictionary<int,string> Y;
Y.add(3,"2third2");
Y.add(4,"2forth2");
Y.add(5,"fifth");
Y.add(6,"sixth");
Y.print();

cout<<"-------Joining two dictionaries---------"<<endl;
dictionary<int,string> Z;
Z.join(X,Y);

cout<<"Dictionary X after"<<endl;
X.print();

cout<<"Dictionary Y after"<<endl;
Y.print();

cout<<"Dictionary Z after"<<endl;
Z.print();

cout<<"-------Searching by key---------"<<endl;
cout<<"Searching dictionary X"<<endl;
X.find_by_key(3);
cout<<endl;

cout<<"Searching dictionary Y"<<endl;
Y.find_by_key(3);
cout<<endl;

cout<<"Searching dictionary Z"<<endl;
Z.find_by_key(3);
cout<<endl;

cout<<"-------Searching by key when key doesn't exist---------"<<endl;
Y.find_by_key(2);
cout<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

cout<<"--------Creating dictionary U key int info int--------"<<endl;
dictionary<int,int> U;
U.add(1,1);
U.add(2,2);
U.add(3,3);
U.add(4,4);
U.add(5,5);
U.print();

cout<<"--------Added key that is not unique--------"<<endl;
U.add(1,1);
U.print();

cout<<"-------Removing by key---------"<<endl;
U.remove_by_key(5);
U.print();

cout<<"-------Removing by key when key doesn't exist---------"<<endl;
U.remove_by_key(5);
U.print();

cout<<"--------Creating dictionary V key int info int--------"<<endl;
dictionary<int,int> V;
V.add(3,232);
V.add(4,242);
V.add(5,5);
V.add(6,6);
V.print();

cout<<"-------Joining two dictionaries---------"<<endl;
dictionary<int,int> W;
W.join(U,V);

cout<<"Dictionary U after"<<endl;
U.print();

cout<<"Dictionary V after"<<endl;
V.print();

cout<<"Dictionary W after"<<endl;
W.print();

cout<<"-------Searching by key---------"<<endl;
cout<<"Searching dictionary U"<<endl;
U.find_by_key(3);
cout<<endl;

cout<<"Searching dictionary V"<<endl;
V.find_by_key(3);
cout<<endl;

cout<<"Searching dictionary W"<<endl;
W.find_by_key(3);
cout<<endl;

cout<<"-------Searching by key when key doesn't exist---------"<<endl;
V.find_by_key(2);
cout<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

cout<<"--------Creating dictionary R key string info int--------"<<endl;
dictionary<string,int> R;
R.add("first",1);
R.add("second",2);
R.add("third",3);
R.add("forth",4);
R.add("fifth",5);
R.print();

cout<<"--------Added key that is not unique--------"<<endl;
R.add("first",1);
R.print();

cout<<"-------Removing by key---------"<<endl;
R.remove_by_key("fifth");
R.print();

cout<<"-------Removing by key when key doesn't exist---------"<<endl;
R.remove_by_key("fifth");
R.print();

cout<<"--------Creating dictionary S string info int--------"<<endl;
dictionary<string,int> S;
S.add("third",232);
S.add("forth",242);
S.add("fifth",5);
S.add("sixth",6);
S.print();

cout<<"-------Joining two dictionaries---------"<<endl;
dictionary<string,int> T;
T.join(R,S);

cout<<"Dictionary R after"<<endl;
R.print();

cout<<"Dictionary S after"<<endl;
S.print();

cout<<"Dictionary T after"<<endl;
T.print();

cout<<"-------Searching by key---------"<<endl;
cout<<"Searching dictionary R"<<endl;
R.find_by_key("third");
cout<<endl;

cout<<"Searching dictionary S"<<endl;
S.find_by_key("third");
cout<<endl;

cout<<"Searching dictionary T"<<endl;
T.find_by_key("third");
cout<<endl;

cout<<"-------Searching by key when key doesn't exist---------"<<endl;
S.find_by_key("second");
cout<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

cout<<"--------Creating dictionary O key string info string--------"<<endl;
dictionary<string,string> O;
O.add("first","first");
O.add("second","second");
O.add("third","third");
O.add("forth","forth");
O.add("fifth","fifth");
O.print();

cout<<"--------Added key that is not unique--------"<<endl;
O.add("first","first");
O.print();

cout<<"-------Removing by key---------"<<endl;
O.remove_by_key("fifth");
O.print();

cout<<"-------Removing by key when key doesn't exist---------"<<endl;
O.remove_by_key("fifth");
O.print();

cout<<"--------Creating dictionary P key string info string--------"<<endl;
dictionary<string,string> P;
P.add("third","2third2");
P.add("forth","2forth2");
P.add("fifth","fifth");
P.add("sixth","sixth");
P.print();

cout<<"-------Joining two dictionaries---------"<<endl;
dictionary<string,string> Q;
Q.join(O,P);

cout<<"Dictionary O after"<<endl;
O.print();

cout<<"Dictionary P after"<<endl;
P.print();

cout<<"Dictionary Q after"<<endl;
Q.print();

cout<<"-------Searching by key---------"<<endl;
cout<<"Searching dictionary O"<<endl;
O.find_by_key("third");
cout<<endl;

cout<<"Searching dictionary P"<<endl;
P.find_by_key("third");
cout<<endl;

cout<<"Searching dictionary Q"<<endl;
Q.find_by_key("third");
cout<<endl;
cout<<endl;

cout<<"-------Searching by key when key doesn't exist---------"<<endl;
P.find_by_key("second");

cout<<endl<<endl<<endl;

}