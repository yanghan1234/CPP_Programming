#include <iostream>
using namespace std;
const int MAX=1000;
//设计联系人的结构体
struct Person
{
    //姓名
    string m_Name;
    //性别
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};
//涉及通讯录的结构体
struct Addressbooks
{
    //通讯录中保存的联系人的数组
    struct Person personArray[MAX];
    //通讯录中当前记录联系人个数
    int m_Size;
};
//1.添加联系人
void addPerson(Addressbooks *abs)
{
    //判断通讯录是否已满，如果满了，则不再添加
    if (abs->m_Size==MAX)
    {
        cout<<"通讯录已满，无法添加！"<<endl;
        return;
    }
    else
    {
      //1.添加具体联系人
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;
        //性别
        cout<<"请输入性别是："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        int sex=0;
        while (true)
        {
            //如果输入的是1或者2可以退出循环，因为输入的是正确值
            //如果输入的有误，则重新输入
            cin>>sex;
            if (sex==1||sex==2)
            {
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout<<"输入有误，请重新输入";
        }
        //年龄
        cout<<"请输入年龄："<<endl;
        int age=0;
        while (true)
        {
            //如果输入的年龄在0到100之间就可以退出循环，因为输入的是正确值
            //如果输入的有误，则重新输入
            cin>>age;
            if (age>0&&age<100)
            {
                abs->personArray[abs->m_Size].m_Age=age;
                break;
            }
            cout<<"输入有误，请重新输入";
        }
        cout<<"请输入联系电话："<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone=phone;
        //家庭住址
        cout<<"请输入家庭住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;
        //更新一下通讯录中的人数
        abs->m_Size++;
        cout<<"添加成功"<<endl;
        system("pause");//请按任意键继续
        system("cls");//清屏操作
    }
}
//2.显示所有的联系人
void showPerson(Addressbooks *abs)
{
    //判断通讯录中人数是否为零，如果为0，提示记录为空
    //如果不为0，显示记录的联系人信息
    if (abs->m_Size==0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for (int i=0;i<abs->m_Size;i++)
        {
            cout<<"姓名: "<<abs->personArray[i].m_Name<<"\t";
            cout<<"性别："<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";
            cout<<"年龄："<<abs->personArray[i].m_Age<<"\t";
            cout<<"电话："<<abs->personArray[i].m_Phone<<"\t";
            cout<<"住址："<<abs->personArray[i].m_Addr<<"\t";
        }
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作
}
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks *abs,string name)
{
    for (int i=0;i<abs->m_Size;i++)
    {
        if (abs->personArray[i].m_Name==name)
        {
            return i;//如果找到了，就返回这个人在数组中的下标编号
        }
    }
    return -1;//如果遍历结束都没有找到，就返回-1
}
//3.删除指定的联系人
void deletePerson(Addressbooks *abs)
{
    cout<<"请输入您要删除的联系人："<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs, name);//ret==-1 未查到 ret!=-1 查到了
    if (ret!=-1)
    {
       //查到人了，要进行删除操作
        for (int i=ret;i<abs->m_Size;i++)
        {
            //数据前移操作
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_Size--;//更新一下通讯录中的人员数
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}
//4.查找指定的联系人信息
void findPerson(Addressbooks *abs)
{
    cout<<"请输入您要查找的联系人"<<endl;
    string name;
    cin>>name;
    //判断指定的联系人是否存在通讯录中
    int ret=isExist(abs, name);
    if (ret!=-1)//找到联系人
    {
        cout<<"姓名："<<abs->personArray[ret].m_Name<<"\t";
        cout<<"性别："<<abs->personArray[ret].m_Sex<<"\t";
        cout<<"年龄："<<abs->personArray[ret].m_Age<<"\t";
        cout<<"电话："<<abs->personArray[ret].m_Phone<<"\t";
        cout<<"住址："<<abs->personArray[ret].m_Addr<<endl;
    }
    else //未找到联系人
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}
//5.修改指定的联系人信息
void modifyPerson(Addressbooks *abs)
{
    cout<<"请输入一下您要修改的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if (ret!=-1)//找到指定联系人
    {
        //姓名
        string name;
        cout<<"请输入一下姓名："<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;
        //性别
        cout<<"请输入性别："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        int sex=0;
        while (true)
        {
        cin>>sex;
        if (sex==1||sex==2)
        {
            //输入正确，退出循环输入
            abs->personArray[ret].m_Sex=sex;
            break;
        }
            cout<<"输入有误，请重新输入"<<endl;
        }
        //年龄
        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        while (true)
        {
            //如果输入的年龄在0到100之间就可以退出循环，因为输入的是正确值
            //如果输入的有误，则重新输入
            cin>>age;
            if (age>0&&age<100)
            {
                abs->personArray[ret].m_Age=age;
                break;
            }
            cout<<"输入有误，请重新输入";
        }
        //电话
            cout<<"请输入联系电话："<<endl;
            string phone;
            cin>>phone;
            abs->personArray[ret].m_Phone=phone;
        //住址
        cout<<"请输入家庭住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr=address;
        cout<<"修改成功！"<<endl;
    }
            else //未找到联系人
    {
        cout<<"查无此人"<<endl;
    }
    //按任意键后清屏
    system("pause");
    system("cls");
}
//6.清空联系人
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size=0;
    cout<<"通讯录已清空"<<endl;
    //按任意键后清屏
    system("pause");
    system("cls");
}
void showMenu()
{
    cout<<"**********************"<<endl;
    cout<<"***** 1.添加联系人 *****"<<endl;
    cout<<"***** 2.显示联系人 *****"<<endl;
    cout<<"***** 3.删除联系人 *****"<<endl;
    cout<<"***** 4.查找联系人 *****"<<endl;
    cout<<"***** 5.修改联系人 *****"<<endl;
    cout<<"***** 6.清空联系人 *****"<<endl;
    cout<<"***** 0.退出通讯录 *****"<<endl;
    cout<<"**********************"<<endl;
}
int main()
{
    //创建一个通讯录的结构体变量
    Addressbooks abs;
    //初始化通讯录中当前的人员个数
    abs.m_Size=0;
    int select=0;  //创建一个用户输入的变量
     while (true)
     {
         showMenu();
         cin>>select;
         switch (select)
         {
             case 1:
                 addPerson(&abs);// 1.添加联系人  2.利用地址传递可以修饰实参
                 break;
             case 2:
                 showPerson(&abs);//2.显示联系人
                 break;
             case 3:
                 deletePerson(&abs);//删除联系人
                 break;
             case 4:
                 findPerson(&abs);//4.查找联系人
                 break;
             case 5:
                 modifyPerson(&abs);//5.修改联系人
                 break;
             case 6:
                 cleanPerson(&abs);//6.清空联系人
                 break;
             case 0://0.退出通讯录
                 cout<<"欢迎下次使用通讯录."<<endl;
                 return 0;
             default:
                 break;
         }
     }
}
