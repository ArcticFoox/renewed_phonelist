#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

struct Phone{
    string name;
    string phone_num;
};

bool compare(const Phone &a, const Phone &b){
    return a.name < b.name;
}

void save(){

}

void load(){

}

void Phone_add(list<Phone>& phonebook, string name, string phone_num){
    Phone tmp;
    tmp.name = name;
    tmp.phone_num = phone_num;

    phonebook.push_back(tmp);
    phonebook.sort(compare);
}

void Phone_modify(list<Phone>& phonebook, string name){
    list<Phone>::iterator it;
    vector<list<Phone>::iterator> c_it;
    int who, which, which2;
    string write;
    for(it = phonebook.begin(); it != phonebook.end(); it++){
        if(it->name == name){
            c_it.push_back(it);
        }
    }
    
    cout << "who do you want to modify \n";
    for(int i = 0; i < c_it.size(); i++){
        cout << i + 1 << " " << c_it[i]->name << " " << c_it[i]->phone_num << "\n";
    }
    cin >> who;

    cout << "which one do you want to modify \n";
    cout << "1 name  2 phonenum  3 return\n";

    cin >> which;
    if(which == 1){
        cout << "Enter the name\n";
        cin >> write;
        c_it[who - 1]->name = write;
    }
    else if(which == 2){
        cout << "Enter the phonenum\n";
        cin >> write;
        c_it[who - 1]->phone_num = write;
    }
    else{
        return;
    }
    
    phonebook.sort(compare);
}

void Phone_remove(list<Phone>& phonebook, string name){
    list<Phone>::iterator it;
    vector<list<Phone>::iterator> c_it;
    int who;
    for(it = phonebook.begin(); it != phonebook.end(); it++){
        if(it->name == name)
            c_it.push_back(it);
    }

    cout << "who do you want to remove \n";
    for(int i = 0; i < c_it.size(); i++){
        cout << i + 1 << " " << c_it[i]->name << " " << c_it[i]->phone_num << "\n";
    }
    cin >> who;

    phonebook.erase(c_it[who - 1]);
}

void Phone_list(list<Phone>& phonebook){
    list<Phone>::iterator it;

    for(it = phonebook.begin(); it != phonebook.end(); it++){
        cout << it->name << it->phone_num << "\n";
    }
}

void Phone_serach(list<Phone>& phonebook, string name){
    list<Phone>::iterator it;

    for(it = phonebook.begin(); it != phonebook.end(); it++){
        if(it->name == name)
            cout << it->name << it->phone_num << "\n";
    }
}

int main(){
    list<Phone> phonebook;
    string name;
    string phonenum;
    bool it = true;
    while(it){
        int button;
        cout << "add 1, modify 2, remove 3, list 4, search 5, escape 6" << "\n";
        cin >> button;
        switch(button){
            case 1:
                cout << "Enter name and phonenumber\n";
                cin >> name >> phonenum;
                Phone_add(phonebook, name, phonenum);
                break;
            case 2:
                cout << "Enter the name\n";
                cin >> name;
                Phone_modify(phonebook, name);
                break;
            case 3:
                cout << "Enter the name\n";
                cin >> name;
                Phone_remove(phonebook, name);
                break;
            case 4:
                Phone_list(phonebook);
                break;
            case 5:
                cout << "Enter the name\n";
                cin >> name;
                Phone_serach(phonebook, name);
                break;
            case 6:
                it = false;
                break;
            default:
                cout << "wrong button try again" << "\n";
                break; 
        }
    }

    return 0;
}