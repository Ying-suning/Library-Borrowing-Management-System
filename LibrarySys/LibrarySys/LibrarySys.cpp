#include <iostream>
#include "Resource.h"
#include "Book.h"
#include "Student.h"
#include "BookMall.h"
#include "UniqueFeature.h"
#include "Magazine.h"
#include "EResource.h"

using namespace std;

int main()
{
    cout << "===== 图书馆管理系统=====\n" << endl;
    BookMall lib;

    lib.addResource(new Book("C++程序设计", "晓晓", "978-7-111-24212-3", "1495584", "人民邮电出版社", 59.0, 1));
    lib.addResource(new Magazine("计算机学报", "2026第3期", "M001", true));
    lib.addResource(new EResource("C++教学视频", "xxxxxxxxxx", "E001", true));

    lib.showAllResources();

    Student s1("5120250001", "小红");
    lib.addStudent(s1);

    lib.showAllResources();
    lib.showAllStudents();

    cout << "\n====小红借阅====" << endl;
    lib.borrowResource("5120250001", "1495584");
    lib.borrowResource("5120250001", "M001");
    lib.showAllResources();

    lib.showAllStudents();

    cout << "\n====小红还书====" << endl;
    lib.returnResource("5120250001", "1495584");
    lib.showAllResources();

    UniqueFeature feat;
    Resource* availableBook = lib.findResourceById("1495584");
    if (availableBook) feat.addBook(availableBook);
    feat.execute();

    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
