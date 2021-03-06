#include <iostream>
#include <stack>
#include <string>

int main(){
    std::string s,w="";

    std::stack <std::string> myStack;

    long long int q;
    int op,k;

    std::cin>>q;

    for(int i=0;i<q;i++){
        std::cin >> op;
        if(op==1){
            std::cin>>w;
            //Push s into the stack, before performing append
            myStack.push(s);
            s += w;
        }else if(op==2){
            std::cin>>k;
            //Push s into the stack before removing last k elements
            myStack.push(s);

            //Remove last k elements
            while(k>0){
                s.pop_back();
                k--;
            }
        }else if(op==3){
            std::cin>>k;
            std::cout<<s[k-1]<<std::endl;
        }else if(op==4){
            s = myStack.top();
            myStack.pop();
        }
    }

    return 0;
}
