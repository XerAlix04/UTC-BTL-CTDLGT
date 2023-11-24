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
                tail->getnext()->setprev(tail);
				tail=tail->getnext();
			}
			num++;
		}
		void push_front(Student x){
			if(num==0) head=tail=new node(x);
			else{
				head->setprev(new node(x));
                head->getprev()->setnext(head);
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
        void insert(node *p, Student x){
            if(num==0) head=tail=new node(x);
            else{
                node *q;
                q->setelem(x);
                q->setnext(p->getnext());
                p->getnext()->setprev(q);
                q->setprev(p);
                p->setnext(q);
            }
            num++;
        }
        void remove(node *p){
            p->getprev()->setnext(p->getnext());
            p->getnext()->setprev(p->getprev());
            p->setnext(NULL);
            p->setprev(NULL);
            delete p;
            num--;
        }
};
class Manager{
    node *head, *tail;
    dlist HS;
    public:
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
                    HS.push_back(x);
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
                    HS.push_back(x);
                }
                file.close();
            }
            
        }
        void InXepLoaiHS(){
            Student x;
            for (dlist::iterator it = HS.begin(); it != HS.end(); it++){
                node *t = it.getcurr();
                x = t->getelem();
                cout << x.HoTen << "\n" << "Xếp loại: ";
                if (x.Diem>=8.5) cout << "Học sinh Giỏi";
                else if (x.Diem>=7.0) cout << "Học sinh Khá";
                else if (x.Diem>=5.5) cout << "Học sinh Trung bình";
                else if (x.Diem>=4.0) cout << "Học sinh Trung bình yếu"; 
                else cout << "Học sinh Kém";  
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
        void TimHS(string name, string cl){
            Student x; int i=0;
            for (dlist::iterator it = HS.begin(); it != HS.end(); it++){
                node *t = it.getcurr();
                x = t->getelem();
                if (x.HoTen==name && x.Lop==cl) cout << x.SDT; i++;
                break;
            }
            if (i==0) cout << "Không có học sinh nào tên " << name << " trong lớp " << cl;
        }
        void AddHS(string name, string cl, int phone, float grade){
            Student x;
            x.HoTen=name; x.Lop=cl; x.SDT=phone; x.Diem=grade;
            HS.push_back(x);
        }
        void DeleteLop(string cl){
            Student x;
            for (dlist::iterator it = HS.begin(); it != HS.end(); it++){
                node *t = it.getcurr();
                x = t->getelem();
                if (x.Lop==cl) HS.remove(t); 
            }
        }
        void SortHS(){
            node *h = head;
            node *t = tail;
            quickSort(h,t);
        }
        void quickSort (node *h, node *t){
            if (t!=NULL && h!=t && h!=t->getnext()){
                node *p = Partition(h,t);
                quickSort(h, p->getprev());
                quickSort(p->getnext(), t);
            }
        }
        node *Partition(node *h, node *t){
            Student x = h->getelem();
            Student y;
            node *i = h->getprev();
            int inum=0;
            int jnum = HS.size()+1;
            for (dlist::reverse_iterator it = HS.rbegin(); it != HS.rend(); it++){
                node *j = it.getcurr();
                jnum--;
                y = j->getelem();
                if (y.Diem>=x.Diem){
                    i = (i==NULL)? h : i->getnext(); inum++;
                    swap(&(i->getelem()), &(j->getelem()));
                }
                if (inum>jnum) break;
            }
            i = (i==NULL)? h : i->getnext(); inum++;
            swap(&(i->getelem()), &(t->getelem()));
            return i;
        }
        void swap(Student *a, Student *b){
            Student t = *a;
            *a = *b;
            *b = t;
        }
        void InsertHS(string name, string cl, int phone, float grade){
            Student x, y, z;
            x.HoTen=name; x.Lop=cl; x.SDT=phone; x.Diem=grade;
            for (dlist::iterator it = HS.begin(); it != HS.end(); it++){
                node *t = it.getcurr();
                if (t!=tail){
                    node *v = t->getnext();
                    y = t->getelem();
                    z = v->getelem();
                    if (x.Diem<=y.Diem&&x.Diem>=z.Diem){
                        HS.insert(t, x);
                        break;
                    }
                }
            }
        }
        void Save(){
            string filename;
            Student x;
            cout << "Nhập tên file: "; cin >> filename;
            ofstream file(filename);
            if (!file.is_open()) {
                cout << "Không thể mở tệp" << endl;
            }
            for (dlist::iterator it = HS.begin(); it != HS.end(); it++){
                node *t = it.getcurr();
                x = t->getelem();
                file << x.HoTen << "\n";
                file << x.Lop << "\n";
                file << x.SDT << "\n";
                file << x.Diem << "\n";
            }
            file.close();
        }
};

dlist HS;
Manager M;

int main(){
    int choice, n, phone;
    string name, cl;
    float grade;
    cout << "Nhập 1 để nhập từ bàn phím \n";
    cout << "Nhập 2 để nhập từ file \n";
    cin >> n;
    if (n!=1 && n!=2) cout << "--- Vui lòng nhập 1 hoặc 2 ---" << endl;
    else M.NhapDanhSachHS(n);

        cout << "-------------------------------------------------------\n";
        cout << "Nhập 1 để: In ra danh sách học sinh gồm tên và xếp loại \n";
        cout << "Nhập 2 để: In ra danh sách học sinh gồm các thông tin đầy đủ \n";
        cout << "Nhập 3 để: Tìm học sinh, in ra số điện thoại của học sinh đó \n";
        cout << "Nhập 4 để: Bổ sung hồ sơ học sinh mới vào danh sách \n";
        cout << "Nhập 5 để: Loại bỏ tất cả học sinh của một lớp khỏi danh sách \n";
        cout << "Nhập 6 để: Sắp xếp danh sách học sinh theo thứ tự giảm dần điểm trung bình \n";
        cout << "Nhập 7 để: Chèn hồ sơ học sinh mới vào danh sách đã sắp xếp \n";
        cout << "Nhập 8 để: Lưu trữ lại danh sách học sinh đã thay đổi \n";
        cout << "Nhập 9 để: Thoát \n";
        cout << "-------------------------------------------------------" << endl;
        cout << "Nhập từ 1-9: ";
        cin >> choice;
        switch (choice){
        case 1:
            M.InXepLoaiHS();
            break;
        case 2:
            M.InDanhSachHS();
            break;
        case 3:
            cout << "Nhập tên học sinh cần tìm: "; getline (cin, name);
            cout << "Nhập lớp: "; getline (cin, cl);
            M.TimHS(name, cl);
            break;
        case 4:
            cout << "Nhập tên học sinh mới: "; getline (cin, name);
            cout << "Nhập lớp: "; getline (cin, cl);
            cout << "Nhập số điện thoại: "; cin >> phone;
            cout << "Nhập điểm trung bình: "; cin >> grade;
            M.AddHS(name, cl, phone, grade);
            break;
        case 5:
            cout << "Nhập tên lớp cần xóa: "; getline(cin, cl);
            M.DeleteLop(cl);
            break;
        case 6:
            M.SortHS();
            break;
        case 7:
            cout << "Nhập tên học sinh mới: "; getline (cin, name);
            cout << "Nhập lớp: "; getline (cin, cl);
            cout << "Nhập số điện thoại: "; cin >> phone;
            cout << "Nhập điểm trung bình: "; cin >> grade;
            M.InsertHS(name, cl, phone, grade);
            break;
        case 8:
            M.Save();
            break;
        case 9:
            for (int i = 0; i < 6; i++){
                cout << "END" << endl;
            }
            break;
        default:
            cout << "--- Vui lòng nhập số từ 1 đến 9 ---" << endl;
        }
    return 0;
}