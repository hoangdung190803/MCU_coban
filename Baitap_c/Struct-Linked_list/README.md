1. Bài toán về Struct
Bài 1.1: Quản lý thông tin sinh viên cơ bản
Định nghĩa struct Student gồm các trường: char name[50], int age, float gpa.
Viết chương trình nhập thông tin cho 1 sinh viên, sau đó in ra thông tin đó.
Bài 1.2: Mảng các struct sinh viên
Sử dụng struct Student như trên. Nhập thông tin cho n sinh viên (n ≤ 20), lưu vào mảng struct. In ra danh sách sinh viên và tìm sinh viên có GPA cao nhất.
Bài 1.3: Struct lồng nhau
Định nghĩa struct Date (day, month, year) và struct Employee (name, salary, birth_date kiểu struct Date).
Nhập thông tin cho một nhân viên và in ra dưới dạng đẹp (ví dụ: "Name: ..., Salary: ..., DOB: dd/mm/yyyy").
2. Bài toán về Linked List (Danh sách liên kết đơn)
Bài 2.1: Tạo và in linked list
Định nghĩa struct Node { int data; struct Node* next; }.
Viết các hàm:

Thêm một node vào cuối danh sách.
In toàn bộ danh sách.
Chương trình chính: Tạo danh sách bằng cách thêm các số nguyên từ input cho đến khi nhập -1.

Bài 2.2: Chèn node vào đầu và xóa node đầu
Mở rộng từ bài 7, thêm hàm chèn node vào đầu danh sách và hàm xóa node ở đầu. Thử nghiệm các thao tác này.
Bài 2.3: Tìm và xóa một giá trị
Viết hàm tìm một giá trị trong linked list (trả về con trỏ node nếu tìm thấy).
Viết hàm xóa node có giá trị cho trước (nếu tồn tại nhiều thì xóa node đầu tiên).
Thử nghiệm bằng cách tạo list, in ra, xóa một giá trị, rồi in lại.
Bài 2.4: Đảo ngược linked list
Viết hàm đảo ngược toàn bộ danh sách liên kết (thay đổi các con trỏ next). In danh sách trước và sau khi đảo.