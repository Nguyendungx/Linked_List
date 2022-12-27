#include<iostream>
#include <stdio.h>
#include <conio.h>
#include "graphics.h"

using namespace std;

struct node {
	int data;
	node* next;
};
node* createNode(int x) {
	node* temp = new node;
	temp->next = NULL;
	temp->data = x;
	return temp;
}

node* addElement(node* p, int x) {
	node* temp = createNode(x);
	p->next = temp;
	return temp;
}

node* addHead(node* l, int x) {
	node* temp = new node;
	temp->data = x;
	temp->next = l;
	l = temp;
	return l;
}

node* addAt(node* l, int k, int x) {
	node* p = l;
	for (int i = 0; i < k - 1; i++) {
		p = p->next;
	}
	node* temp = new node;
	temp->data = x;
	temp->next = p->next;
	p->next = temp;

	return l;
}

node* addTail(node* l, int x) {
	node* p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}
node* deleteHead(node* l) {
	node* p = l;
	p = p->next;
	delete(l);
	return p;
}

node* deleteTail(node* l) {
	node* p = l;
	while (p->next->next != NULL) {
		p = p->next;
	}
	delete(p->next);
	p->next = NULL;
	return l;
}

node* deleteAt(node* l, int k) {
	node* p = l;
	for (int i = 0; i < k - 1; i++) {
		p = p->next;
	}
	node* temp = p->next;
	p->next = p->next->next;
	delete(temp);
	return l;
}

node* getNode(node* l, int k) {
	node* p = l;
	for (int i = 0; i < k; i++) {
		p = p->next;
	}
	return p;
}

node* convert(node* l, int a, int b) {
	node* p = l;
	while (p != NULL) {
		if (p->data == a) {
			p->data = b;
		}
		p = p->next;
	}
	return l;
}

void dem(int n, int& t)
{
	while (n != 0)
	{
		//sau một vòng lặp thì count sẽ tăng lên 1
		t++;
		//chia lấy nguyên cho 10, cứ một lần chia thì số n sẽ có một chữ số
		n = n / 10;
	}
}

// Ham in ra man hinh
void printList(node* l) {
	system("cls");
	int t = 0;
	node* p = l;
	node* a = l;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
		t++;
	}
	if (t > 0)
	{
		// Mo hinh
		setcolor(4);
		for (int i = 0; i < t; i++)
		{
			rectangle(400 + i * 90, 300, 470 + i * 90, 330);
			drawText(460 + i * 90, 300, "-->");
		}

		//In gia tri
		for (int j = 0; j < t; j++)
		{
			char temp[5];
			int n = a->data;
			if (a->data != 0)
			{
				int q = 0;
				dem(n, q);
				for (int i = q - 1; i >= 0; i--)
				{
					temp[i] = (n % 10) + 48;
					n = n / 10;
				}
				temp[q] = '\0';
				drawText(420 + (j) * 90, 300, temp);
				a = a->next;
			}
			else
			{
				temp[0] = '0';
				temp[1] = '\0';
				drawText(420 + (j) * 90, 300, temp);
				a = a->next;
			}
		}

		//Khung
		setcolor(9);
		rectangle(400, 250, 470, 290);
		drawText(410, 250, "Head");
		drawText(430, 275, "|");
		circle(520 + (t - 1) * 90, 315, 60);
		drawText(495 + (t - 1) * 90, 300, "NULL");
	}
	else
	{
		setcolor(9);
		rectangle(400, 250, 470, 290);
		drawText(410, 250, "Head");
		drawText(430, 275, "|");
		circle(520 + (t - 1) * 90, 315, 60);
		drawText(495 + (t - 1) * 90, 300, "NULL");
	}

}

void xoaPhanTu(node*& l, int n)
{
	int t = 0;
	node* a = l;
	while (a != NULL) {
		a = a->next;
		t++;
	}
	if (t > 0)
	{
		int k;
		cin >> k;
		if (k == 0) {
			l = deleteHead(l);
		}
		else if (k == n - 1) {
			l = deleteTail(l);
		}
		else {
			l = deleteAt(l, k);
		}
		printList(l);
	}
	else
	{
		cout << "Trong" << endl;
		cout << "Chon vi tri va gia tri muon them." << endl;
		_getch();
	}
}

void themPhanTu(node*& l, node* p, int n)
{
	int t = 0;
	node* a = l;
	while (a != NULL) {
		a = a->next;
		t++;
	}
	if (t >= 5)
	{
		cout << "Chi co the xoa" << endl;
		cout << "Chon vi tri xoa:" << endl;
		xoaPhanTu(l, n);
	}
	else
	{
		int k, x;
		// Them phan tu x vao vi tri k
		cin >> k >> x;
		if (k == 0) {
			l = addHead(l, x);
		}
		else if (k == n) {
			l = addTail(l, x);
		}
		else {
			l = addAt(l, k, x);
		}
		printList(l);
	}

}

void timPhanTu(node* l, node* p)
{
	char s1[] = "Gia tri";
	int k;
	cin >> k;
	p = getNode(l, k);
	cout << p->data << endl;;
	rectangle(405 + k * 90, 360, 465 + k * 90, 400);
	line(400 + k * 90, 360, 430 + k * 90, 340);
	line(470 + k * 90, 360, 430 + k * 90, 340);
	line(400 + k * 90, 360, 470 + k * 90, 360);
	drawText(400 + k * 90, 370, s1);
	cout << "Nhan phim bat ki de tiep tuc." << endl;
	_getch();
}

void chucNang(node*&l,node*p,int n)
{
	printList(l);
	cout << endl;
	cout << "Chon 1 neu muon Add." << endl;
	cout << "Chon 2 neu muon Delete." << endl;
	cout << "Chon 3 neu muon Xuat gia tri." << endl;
	cout << "Nhan phim bat ki de Thoat." << endl;
	cout << "Quy uoc 0 la vi tri cua Head" << endl;
	int t;
	cin >> t;

	//Them phan tu x vao vi tri k
	if (t == 1)
	{
		themPhanTu(l, p, n);
		chucNang(l, p, n);
	}

	// Xoa phan tu tai vi tri x
	else if (t == 2)
	{
		xoaPhanTu(l, n);
		chucNang(l, p, n);
	}

	// Tim phan tu o vi tri k
	else if (t == 3)
	{
		timPhanTu(l, p);
		chucNang(l, p, n);
	}

	else
	{
		exit;
	}
}

int main() {
	initgraph();
	char s1[] = "Press any key to view the program.";
	drawText(400, 50, s1);
	_getch();
	system("cls");

	// Tao danh sach
	cout << "nhap n,gia tri mang." << endl;
	int n, x;
	cin >> n;
	cin >> x;
	node* l = createNode(x);
	node* p = l;
	for (int i = 1; i < n; i++) {
		cin >> x;
		p = addElement(p, x);
	}

	chucNang(l,p,n);

	return 0;
}