#include<iostream>
#include<stdlib.h>
#define element char
using namespace std;
class Stack{
	public:
		Stack(int n);
		element Peer();
		int IsFull();
		int IsEmpty();
		int Size();
		void resize(int n);
		void push(element p);
		void pop(element &p);
		element *item;
	private:
		int size,top,base;
};
void Stack::push(element p){
	cout<<"op Push"<<" ";
	if(IsFull()) resize(size+1);
	item[top++]=p;
}
void Stack::pop(element &p){
	cout<<"op Pop"<<endl;
	if(top==base) cout<<"empty Stack, wrong operation"<<endl;
	else p=item[--top];
}
Stack::Stack(int n){
	element temp;
	top=base=0;
	item=(element*)malloc(10);
	size=10;
	if(size<n) resize(n);
	cout<<"请输入栈内元素"<<n<<"个"<<endl;
	for(int i=1;i<=n;i++){
		cin>>temp;
		push(temp);
	}
}
int Stack::Size(){
	cout<<"op Size"<<endl;
	return top-base;
}
element Stack::Peer(){
	if(!IsEmpty()){
		cout<<"op Peer"<<endl<<item[top-1]<<endl;
	} 
} 
void Stack::resize(int n){
	item=(element*)realloc(item,n*sizeof(element));
	size=n;
}
int Stack::IsFull(){
	cout<<"op IsFull"<<endl;
	return (top-base==size);//1表示栈满，0表示不满 
}
int Stack::IsEmpty(){
	cout<<"op IsEmpty"<<endl;
	return (top==base);//1表示栈空，0表示不空
}
int main(){
	int sizeofStack;
	element ch=0;
	cout<<"请输入元素个数："<<endl;
	cin>>sizeofStack;
	Stack ms(sizeofStack);
	cout<<ms.IsFull()<<endl;
	cout<<ms.IsEmpty()<<endl;
	cout<<ms.Size()<<endl;
	ms.Peer();
	ms.pop(ch);
	cout<<ch<<endl;
	ms.Peer();
	return 0;
}
