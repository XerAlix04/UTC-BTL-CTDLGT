#include<bits/stdc++.h>

using namespace std;

struct Student{
    string HoTen, Lop;
    int SDT;
    float Diem;
};

class node{
    Student elem;
    node *next, *prev;
    public:
        node(){};
        node(Student x){
            next=NULL;
            prev=NULL;
            elem.HoTen=x.HoTen;
            elem.Lop=x.Lop;
            elem.SDT=x.SDT;
            elem.Diem=x.Diem;
        }
        Student &getelem(){
            return elem;
        }
		node *&getprev(){
            return prev;
        }
		node *&getnext(){
            return next;
        }
		void setelem(Student x){
            elem.HoTen=x.HoTen;
            elem.Lop=x.Lop;
            elem.SDT=x.SDT;
            elem.Diem=x.Diem;
        }
		void setprev(node *p=nullptr){
            prev=p;
        }
		void setnext(node *p=nullptr){
            next=p;
        }
};

class dlist_iterator{
	node *curr;
	public:
		dlist_iterator(node *c=0){
            curr=c;
        }
		node *getcurr(){
            return curr;
        }
		dlist_iterator &operator=(dlist_iterator it){
            this->curr=it.getcurr(); 
            return *this;
        }
		bool operator!=(dlist_iterator it){
            return curr!=it.getcurr();
        }
		Student &operator*(){
            return curr->getelem();
        }
		dlist_iterator operator++(int){
            dlist_iterator it=curr;
            curr=curr->getnext(); 
            return it;
        }
		dlist_iterator operator++(){
            curr=curr->getnext(); 
            return curr;
        }
};

class dlist_reverse_iterator{
	node *curr;
	public:
		dlist_reverse_iterator(node *c=0){
            curr=c;
        }
		node *getcurr(){
            return curr;
        }
		dlist_reverse_iterator &operator=(dlist_reverse_iterator it){
            this->curr=it.getcurr(); 
            return *this;
        }
		bool operator!=(dlist_reverse_iterator it){
            return curr!=it.getcurr();
        }
		Student &operator*(){
            return curr->getelem();
        }
		dlist_reverse_iterator operator++(int){
            dlist_reverse_iterator it=curr;
            curr=curr->getprev(); 
            return it;
        }
		dlist_reverse_iterator operator++(){
            curr=curr->getprev(); 
            return curr;
        }
};

class dlist{
	node *head,*tail;
	unsigned int num;
	public:
		typedef dlist_iterator iterator;
		typedef dlist_reverse_iterator reverse_iterator;
		iterator begin(){
            return head;
        }
		iterator end(){
            return nullptr;
        }
		reverse_iterator rbegin(){
            return tail;
        }
		reverse_iterator rend(){
            return nullptr;
        }
		dlist(){
            num=0;
            head=tail=nullptr;
        }
		dlist(int k,Student x){
            num=0;
            head=tail=0; 
            while(k--) push_back(x);
        } //tao list k phan tu bang x
		bool empty(){
            return num==0;
        }
		unsigned size(){
            return num;
        }
		void push_back(Student x){
			if(num==0) head=tail=new node(x);
			else{
				tail->setnext(new node(x));
				tail=tail->getnext();
			}
			num++;
		}
		void push_front(Student x){
			if(num==0) head=tail=new node(x);
			else{
				head->setprev(new node(x));
				head=head->getprev();
			}
			num++;
		}
		Student &front(){
            return head->getelem();
        }
		Student &back(){
            return tail->getelem();
        }
		void pop_back(){
			if(num==0) return;
			if(num==1) head=tail=nullptr;
			else
			{
				tail=tail->getprev();
				tail->setnext(0);
			}
			num--;
		}		
		void pop_front(){
			if(num==0) return;
			if(num==1) head=tail=nullptr;
			else
			{
				head=head->getnext();
				head->setprev(0);
			}
			num--;
		}
        void NhapHoSoHS(Student x){

        }
        void NhapDanhSachHS(int n){
            Student x;
            int m;
            if (n==1) {
                cout << "Số học sinh cần nhập: "; cin >> m;
                for (int i=0; i<m; i++){
                    cout << "Nhập tên học sinh thứ " << m << ": "; getline (cin, x.HoTen);
                    cout << "Nhập lớp: "; getline (cin, x.Lop);
                    cout << "Nhập số điện thoại: "; cin >> x.SDT;
                    cout << "Nhập điểm trung bình: "; cin >> x.Diem;
                    push_back(x);
                }
            }
            else if (n==2){
                string tenfile;
                cout << "Nhập tên file: "; cin >> tenfile;
                ifstream file(tenfile);
                if (!file.is_open()) {
                    cout << "Không thể mở tệp" << endl;
                }
                while (file >> x.HoTen >> x.Lop >> x.SDT >> x.Diem){
                    push_back(x);
                }
                file.close();
            }
            
        }
        void InDanhSachHS(){
            Student x;
            for (dlist::iterator it = HS.begin(); it != HS.end(); it++){
                node *t = it.getcurr();
                x = t->getelem();
                cout << x.HoTen << "\n" << x.Lop << "\n" << x.SDT << "\n" << x.Diem; 
            }
        }
        void TimHS(){
            
        }
        void AddHS(){}
        void DeleteLop(){}
        void SortHS(){}
        void Insert(){}
        void Save(){}
};

dlist HS;

int main(){
    int choice, n;
        cout << "-------------------------------------------------------\n";
        cout << "Nhập 1 để: Nhập danh sách học sinh từ bàn phím hoặc từ file \n";
        cout << "Nhập 2 để: In ra danh sách học sinh gồm tên và xếp loại \n";
        cout << "Nhập 3 để: In ra danh sách học sinh gồm các thông tin đầy đủ \n";
        cout << "Nhập 4 để: Tìm học sinh, in ra số điện thoại của học sinh đó \n";
        cout << "Nhập 5 để: Bổ sung hồ sơ học sinh mới vào danh sách \n";
        cout << "Nhập 6 để: Loại bỏ tất cả học sinh của một lớp khỏi danh sách \n";
        cout << "Nhập 7 để: Sắp xếp danh sách học sinh theo thứ tự giảm dần điểm trung bình \n";
        cout << "Nhập 8 để: Chèn hồ sơ học sinh mới vào danh sách đã sắp xếp \n";
        cout << "Nhập 9 để: Lưu trữ lại danh sách học sinh đã thay đổi \n";
        cout << "-------------------------------------------------------" << endl;
        cout << "Nhập từ 1-9: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Nhập 1 để nhập từ bàn phím \n";
            cout << "Nhập 2 để nhập từ file \n";
            cin >> n;
            if (n!=1 && n!=2) cout << "--- Vui lòng nhập 1 hoặc 2 ---" << endl;
            else HS.NhapDanhSachHS(n);
            break;
        case 2:
            HS.InDanhSachHS();
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 9:
            
            break;
        default:
            cout << "--- Vui lòng nhập số từ 1 đến 9 ---" << endl;
        }
}