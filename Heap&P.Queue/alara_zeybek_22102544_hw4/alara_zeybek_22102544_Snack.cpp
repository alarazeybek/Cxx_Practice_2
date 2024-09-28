/*
 * Alara Zeybek
 * Sec 3
 * 22102544
 * CS202 hw 4
 * Input example: ./a.out "S Apple\nS Chips\nS Cheese\nS Crackers\nC Apple Chips\nC Cheese Crackers\nC Crackers Apple\nC Crackers Chips\nL Crackers\nL Chips\nD Crackers Cheese\nL Crackers\nQ Apple Chips\nQ Cheese Crackers\nX"
 */
#include "alara_zeybek_22102544_Snack.h"
Snack::Snack(string str){
    name = str;
    givenWith = new LinkedList();
}
Snack::Snack(Snack &t){      //copy constructor
    name = t.getName();
    givenWith = new LinkedList(*(t.givenWith));
}
Snack::~Snack(){
    delete givenWith;
}
string Snack::getName(){
    return name;
}
bool Snack::operator==(const Snack &rhs) const {
    return name == rhs.name;
}
Snack* Snack::addAccompanied(string  s){
    if(name != s) {
        bool b = givenWith->addNode(s);
        if (b) {
            return givenWith->getRootItem();
        } else {
            return givenWith->searchNode(s)->item;
        }
    }
    return nullptr;
}
bool Snack::deleteAccompanied(string s){
    if(name != s) {
        return givenWith->deleteNode(s);
    }
    return false;
}
LinkedList* Snack::getGivenWith() {
    return givenWith;
}


LinkedList::LinkedList() {
    root = nullptr;
}
LinkedList::LinkedList(LinkedList& l){
    Node* temp = l.root;
    while(temp != nullptr){
        addNode((temp->item)->getName());
        temp = temp->next;
    }
}
LinkedList::~LinkedList() { //ItemType'ı releaselemedi !! sadece list için kullanilan node alanını bosalatti
    while(root != nullptr){
        Node* temp = root;
        root = root->next;
        delete temp;
    }
}
bool LinkedList::addNode(string i) {
    if(searchNode(i) == nullptr){
        Node* temp = new Node(new Snack(i));   //new kullanıldı
        temp->next = root;
        root = temp;
        return true;
    }
    else{
        cout<<i<<" is already in the list.\n";
        return false;
    }
}

bool LinkedList::deleteNode(string i) {
    if(root != nullptr ) {
        if ((root->item)->getName() == i) {     // want-to-delete item is root
            Node *temp1 = root->next;
            delete root;
            root = temp1;
            return true;
        }
        Node *temp = root;
        while (temp->next != nullptr) {
            if (*(temp->next->item) == i) {
                Node *temptemp = temp->next->next;
                delete temp->next;
                temp->next = temptemp;
                return true;
            }
            temp = temp->next;
        }
        cout << i << " does not exist in the list.\n";
    }
    return false;
}
Node* LinkedList::searchNode(string i) {
    if(root != nullptr) {
        Node *temp = root;
        while (temp != nullptr) {
            if ((temp->item)->getName() == i) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return nullptr;
}
void LinkedList::printLinkedList() {
    Node* temp = root;
    while(temp != nullptr){
        cout<<temp->item->getName()<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
bool LinkedList::isEmpty(){
    return root == nullptr;
}
Snack* LinkedList::getRootItem(){
    return root->item;
}