#include <iostream>

using namespace std;

int main()
{
    int user;
    while(user!=7)
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. View Wish List"<<endl;
        cout<<"2. Add to Wish List"<<endl;
        cout<<"3. Delete from Wish List"<<endl;
        cout<<"4. Compare Items"<<endl;
        cout<<"5. Make a decision"<<endl;
        cout<<"6. Save wish list"<<endl;
        cout<<"7. Quit"<<endl;
        cin >>user;
    }
    return 0;
}
