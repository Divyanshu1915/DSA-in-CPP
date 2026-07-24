#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int a(int arraylength);
int SORT(int len);
void SORT2(int len,int arr[]);
void SORT3(int len,int arr[]);
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.

 //   const auto lang = "C++";
 //   std::cout << "Hello and welcome to " << lang << "\n";
 //    int x,y;
 //   std:: cout<<"Enter the value of the first variable(x)";
 //    std::cin>>x;
 //    std::cout<<"Enter the value of the second variable(y)";
 //    std::cin>>y;
 //
 //    int FUNC(int x,int y);
 //    int result =FUNC(x,y);
 //    std::cout<<result;
 //    int arrlength;
 //    std::cout<<"Enter the length of tge array";
 //
 //
 //    std::cin>>arrlength;
 //
 //     int b;
 // std::cout<<b;
 //    std::cout<<std::endl;
 //
 //
 //     std::cout<<a(arrlength);

     //for the Bubble sort
    int len;
    std::cout<<"Enter the length of the array ";
    std::cin>>len;
    int arr[len];
    for (int i=0;i<len;i++) {
        std::cout<<"Enter the element at index"<<i<<"of ARRAY:";
        std::cin>>arr[i];
    }
    std::cout<<"SELECT the sorting you want to perform"<<std::endl;
    std::cout<<"1 for BUBBLE SORT"<<std::endl;
    std::cout<<"2 for SELECTION SORT"<<std::endl;
    int choice;
    std::cin>>choice;
    switch (choice) {
        case 1:
            std::cout<<SORT(len);//BUBBLESORT
        case 2:
            SORT2(len,  arr);
        case 3:
            SORT3(len,arr);
        default:
            std::cout<<"INVALID CHOICE"<<std::endl;
    }



    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
