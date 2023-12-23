#include<vector>

using namespace std;


int main(){
    // Khai bao
    vector < int > integer_list;
    // Vector khoi tao 10 gia tri 1
    vector < int > integer_list(10, 1);

    // size() 
    // Trả về kích thước của vector
    cout << integer_list.size();

    // push_back(x)	
    // Thêm phần tử x vào cuối vector
    integer_list.push_back(10);

    // pop_back()
    // Xóa phần tử ở cuối vector
    integer_list.pop_back();

    // resize(n, x)
    // Khởi tạo vector với kích thước n và tất cả mọi vị trí đều mang giá trị x. 
    // Nếu không có tham số x thì sẽ để mặc định là 0
    // hoặc rỗng (với chuỗi và kí tự)
    integer_list.resize(10, 1);

    // front()	
    // Trả về phần tử ở đầu vector
    cout << integer_list.front();

    // back()	
    // Trả về phần tử ở cuối vector	
    cout << integer_list.back();

    // begin()
    // Trả về địa chỉ của phần tử đầu tiên trong vector. 
    // Muốn truy cập vào giá trị của địa chỉ đó, ta dùng toán tử *
    cout << *integer_list.begin();

    // end()
    // Trả về địa chỉ của phần tử đứng sau phần tử cuối cùng của vector. 
    // Phần tử này không mang giá trị, nó chỉ dùng để chốt cuối vector
    for (auto it = integer_list.begin(); it != integer_list.end(); ++it){
        // Do something
    }

    // reverse(l, r)
    // Đảo ngược vector từ vị trí l tới vị trí r - 1
    // Đảo ngược toàn dãy 
    reverse(integer_list.begin(), integer_list.end());

    
}