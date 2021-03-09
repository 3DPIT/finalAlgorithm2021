//#include <stdio.h>
//
//typedef struct Node {
//	char data;
//	struct Node *prev;
//}Node;
//typedef struct Stack {
//	int size;
//	Node *top;
//}Stack;
//Stack *create(void)
//{
//	Stack *s = new Stack;
//	s->size = 0;
//	s->top = NULL;
//	return s;
//}
//void push(Stack *s, char data) {
//	Node *newnode = new Node;
//	newnode->data = data;
//	newnode->prev = NULL;
//	if (s->size == 0) {
//		s->top = newnode;
//	}
//	else {
//		newnode->prev = s->top;
//		s->top = newnode;
//	}
//	s->size++;
//}
//void pop(Stack *s)
//{
//	if (s->size == 0)return;
//	else {
//		Node *temp = s->top;
//		s->top = temp->prev;
//		delete temp;
//		s->size--;
//	}
//}
//void deleteStack(Stack *s) {
//	while (s->size != 0) pop(s);
//	delete s;
//}
//int main(void)
//{
//	Stack *s = create();
//	char arr[10000] = { 0, };
//	int sum = 0;
//	scanf("%s", arr + 1);
//	int idx = 0;
//	while (arr[++idx] != NULL);
//	int temp = 1;
//	int visit[10000];
//	int cnt = 0;
//	for (int i = 1; i <= idx; i++)
//	{
//		if (arr[i] == '(') {
//			temp = temp * 2;
//			cnt++;
//			push(s, arr[i]);
//		}
//		if (arr[i] == ')') {
//			if (arr[i - 1] == '(') sum = sum + temp;
//			if (s->size == 0) continue;
//			cnt++;
//			if (s->top->data == '(') pop(s);
//			temp = temp / 2;
//		}
//		if (arr[i] == '[') {
//			temp = temp * 3;
//			cnt++;
//			push(s, arr[i]);
//		}
//		if (arr[i] == ']') {
//			if (arr[i - 1] == '[') sum = sum + temp;
//			if (s->size == 0)continue;
//			cnt++;
//			if (s->top->data == '[')pop(s);
//			temp = temp / 3;
//		}
//	}
//
//	if (s->size==0&&cnt == idx-1)
//		printf("%d\n", sum);
//	else
//		printf("0\n");
//	return 0;
//}
#include<stdio.h>
#include<stack>
#include<iostream>
#include<string>
using  namespace std;
string s;//괄호 입력으로 받기
void init() {//초기화 및 초기입력
	s.clear();
	
	cin >> s;
	s.insert(s.begin(), '0');
}
void stack1() {
	stack<char>ss;//스택
	int temp = 1;
	int sum = 0;
	int cnt = 0;
 	for (int i = 1; i <= s.size(); i++) {
		if (s[i] == '(') {
			temp = temp * 2;
			cnt++;
			ss.push('(');
		}
		else if (s[i] == ')') {
			if (s[i - 1] == '(') sum = sum + temp;
			if (ss.size() == 0) continue;
			cnt++;
			if (ss.top() == '(') ss.pop();
			temp = temp / 2;
		}
		else if (s[i] == '[') {
			temp = temp * 3;
			cnt++;
			ss.push('[');
		}
		else if (s[i] == ']') {
			if (s[i - 1] == '[') sum = sum + temp;
			if (ss.size() == 0) continue;
			cnt++;
			if (ss.top() == '[') ss.pop();
			temp = temp / 3;
		}
	}
	if(ss.size()==0&&cnt==s.size()-1)
	cout << sum << endl;
	else cout << 0 << endl;
}
int main(void) {
	init();
	stack1();
}
