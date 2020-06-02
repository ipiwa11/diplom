#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std; 

double distance_to(double d_lagitude, double d_longitude, double a_lagitude, double a_longitude, int average_speed){
   //d_lagitude, a_lagitude - ������ �����������/����������
   //d_longitude, a_longitude - ������� �����������/����������
   
   int katet_1, katet_2;
   double value_return = 0;
   
   katet_1 = fabs(d_lagitude - a_lagitude);
   katet_2 = fabs(d_longitude - a_longitude);
   
   if (average_speed == 0){
      value_return = sqrt(pow(katet_1, 2) + pow(katet_2, 2)); //���� �������� �� ������ ��� ���� ����� ������ ������ ����������
   } 
   else if(average_speed > 0){
      value_return = sqrt(pow(katet_1, 2) + pow(katet_2, 2)) / average_speed * 60;//���� �������� ������ � ����� ��������� �����
   }
   
   return value_return; // ����������/�����
}

double matrix_value(){

   double arrayrand[6];
   double value = rand() % 20 + 55.0;
   double decimal = 10;
   for(int i = 0; i < 6; i++){
      arrayrand[i] = (rand() % 10 + 1) / decimal;
      value = value + arrayrand[i];
      decimal = decimal * 10;
   }
   return value;
}

int main(){
   
   int i, j = 0;
   int row = 5, colomn = 4, average_speed = 40;
   srand(time(0));
   double arr_studio[row][3], arr_photograph[row][3], arr_client[1][3]; //��������� ������� 
                                                                                                            //�������: [0] - ID(�������������), [1] - latitude(������), [2] - longtitude(�������)
   cout << endl << "<<<���� ������>>>" << endl << endl;
   //���� ������
   for(i = 0; i < row; i++){
        arr_studio[i][0] = i + 1;//������ ������������� ������ ������   
      }
   
   for (i = 0; i < row; i++){
      arr_studio[i][1] = matrix_value();//������ ������
      arr_studio[i][2] = matrix_value();//������� ������
      cout << "������ ID[" << arr_studio[i][0] << "]: ������ = " << setprecision(8) << arr_studio[i][1] << " | ������� = " << arr_studio[i][2] << endl;
   }
   //����������
   cout << endl << "<<<���� ���������>>>" << endl << endl;
   //���� ��������
   for(i = 0; i < row; i++){
        arr_photograph[i][0] = i + 1;//������ ������������� ������� ���������
   }
   
   for (i = 0; i < row; i++){
      arr_photograph[i][1] = matrix_value();//������ ���������
      arr_photograph[i][2] = matrix_value();//������� ���������
      cout << "�������� ID[" << arr_photograph[i][0] << "]: ������ = " << setprecision(8) << arr_photograph[i][1] << " | ������� = " << arr_photograph[i][2] << endl;
   }
   //����������
   cout << endl << "<<<���� ������>>>" << endl << endl;
   //���� ������
   for(i = 0; i < 1; i++){
        arr_client[i][0] = i + 1;//������ ������������� ������� ���������
   }
   
   for (i = 0; i < 1; i++){
      arr_client[i][1] = matrix_value();//������ ���������
      arr_client[i][2] = matrix_value();//������� ���������
      cout << "������ ID[" << arr_client[i][0] << "]: ������ = " << setprecision(8) << arr_client[i][1] << " | ������� = " << arr_client[i][2] << endl;
   }
   //����������
   cout << endl << "<<<���� ��������>>>" << endl << endl;
   //------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
   
   //------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   //���� ������ ����������
   int size_dps = row * row;
   double arr_dcs[row][colomn]; //arr_distance_from_client_to_studio //���������� �� ������� �� ������
//   double arr_dps[size_dps] [colomn]; //arr_distance_from_photograph_to_studio //���������� �� ��������� �� ������
   /*
            ��������� ������� (�������)
    [0] - ID �������/���������|| [1] - ID ������ || [2] - ���������� �� ������� �� ������ || [3] - ����� �� ������� �� ������ ||
    ����� ������� ������� �� �������� ����������� (�� �������/��������� �� ������)
    */
   //���������� � ����� �� ������� �� ������
   int count = 0;
      
   for(i = 0; i < 1; i++){
      for(j =0; j < row; j++){
         arr_dcs[count][0] = arr_client[i][0];
         arr_dcs[count][1] = arr_studio[j][0];
         arr_dcs[count][2] = distance_to(arr_client[i][1], arr_client[i][2], arr_studio[j][1], arr_studio[j][2], 0);
         arr_dcs[count][3] = distance_to(arr_client[i][1], arr_client[i][2], arr_studio[j][1], arr_studio[j][2], average_speed);
         //����� ������ ��������
         cout << setprecision(2) << "ID ������� [" << arr_dcs[count][0] << "] ID ������ [" << arr_dcs[count][1] << "] ���������� (��): " << arr_dcs[count][2] << " ����� (���): " << arr_dcs[count][3] << endl; 
         count ++;
      }
      cout << "[---------------------------------------------------------------------]" << endl;
   }
   
   count = 0;

   double time_crts = 0, //time_client_ready_to_spend //�����, ������� ������ ����� ��������� �� ������ (���)
               time_wp = 60.0; //time_work_photograph //����� ������ ��������� (������ ��� ����) (���)
   
   cout << endl << "������� �����, ������� ������ ����� ��������� �� ������ (���): "; 
   //time_crts = 80;
  // cin >> time_crts;
   
   //���������� ������ �� ��������� ���������� ������,
   // � ����� � ������� ��������� ���������� �������
    double time_rm; //���������� ����� = ����� ������� ������ ����� ��������� - ����� ������ ���������
      
   bool flag=true;
   while(flag){
      flag = false;
      cin >> time_crts;
   
      time_rm = time_crts - time_wp;
      
      if(time_rm <= 0){
         cout << endl << "������! ������ ������� ��������� ���������� �������" << endl;
         flag = true;
      }
      if(flag != true){
         for(i = 0; i < row; i++){
            if (time_rm < arr_dcs[i][3]){
               flag=true;
            }
            else{ 
               flag=false;
               break;
            }              
         }
      }
         if(flag){
            cout << "������, ��� ���������� ������" << endl;
            cout << endl << "������� �����, ������� ������ ����� ��������� �� ������ (���): ";
         }
   }
         
         
   vector <int> arr_idSort;   
   for(i = 0; i < row; i++){
      if(arr_dcs[i][3] < time_rm){
         arr_idSort.push_back(i);//�.�. 1 ������, ��� ������� ����� ������ ��������� � ������
      }
   }
   int size_sort_arr_id = 0, size_arr_phot = 0;
   size_sort_arr_id = arr_idSort.size();
   size_arr_phot = (sizeof(arr_photograph) / sizeof(arr_photograph[0]));
   int size_arrIS = size_arr_phot * size_sort_arr_id;
   double arr_IdSample[size_arrIS][colomn]; //������� ����� ������, � ������� ����� ���������� ��� ������
   
   cout << endl;
   
   //���������� ���������� � ����� �� ������� ��������� (������ ����) �� ������ ��������� (�������) ������ (��������� ����)
   for(i = 0; i < size_arr_phot; i++){
      for(j =0; j < size_sort_arr_id; j++){
         arr_IdSample[count][0] = arr_photograph[i][0]; //������������� ���������
         arr_IdSample[count][1] = arr_studio[arr_idSort[j]][0]; //������������� ������
         arr_IdSample[count][2] = distance_to(arr_photograph[i][1], arr_photograph[i][2], arr_studio[arr_idSort[j]][1], arr_studio[arr_idSort[j]][2], 0); //������ ���������
         arr_IdSample[count][3] = distance_to(arr_photograph[i][1], arr_photograph[i][2], arr_studio[arr_idSort[j]][1], arr_studio[arr_idSort[j]][2], average_speed); //������ �������
         //����� ������ ��������
         cout << setprecision(2) << "ID ��������� [" << arr_IdSample[count][0] << "] ID ������ [" << arr_IdSample[count][1] << "] ���������� (��): " << arr_IdSample[count][2] << " ����� (���): " << arr_IdSample[count][3] << endl; 
         count++;
      }
      cout << "[---------------------------------------------------------------------]" << endl;
   }
   
   count = 0;
   //���������� ���������� �� �����������, �� ����, ��� ������� ������ �� ������
   //�� ����������
   
   for (i = 0; i < size_arrIS; i++){
        for (j = 1; j < (size_arrIS - i);  j++) {
        if (arr_IdSample[j][3] < arr_IdSample[j-1][3]) {
            for(int k = 0; k < colomn; k++){    
               swap (arr_IdSample[j-1][k], arr_IdSample[j][k]);
            }
        } 
        else if (arr_IdSample[j] == arr_IdSample[j-1] and arr_IdSample[j] < arr_IdSample[j-1]){
            for(int k = 0; k < colomn; k++){
               swap (arr_IdSample[j-1][k], arr_IdSample[j][k]);
            }
        }
        }
    }
   
   cout << endl << "[--------------- �������� ��������������� ������ ���������� ---------------]" << endl;
    
    for(i = 0; i < 3; i++){
      cout << setprecision(2) << "ID ��������� [" << arr_IdSample[i][0] << "] ID ������ [" << arr_IdSample[i][1] << "] ���������� (��): " << arr_IdSample[i][2] << " ����� (���): " << arr_IdSample[i][3] << endl; 
    }
    
   cout << endl << "[---------------------------------- ����������� ������� ----------------------------------]" << endl << endl;
   
   double time_output = 0;
 // ����� ������� ������� �������   
   for(i = 0; i < 3; i++){
      int arr_i = arr_IdSample[i][1] - 1;
      cout << endl << "�������� �����: " << arr_IdSample[i][3] << " ������ �����: " << arr_dcs[arr_i][3] << " ID ������: " << arr_dcs[arr_i][1] << endl;
      if(arr_IdSample[i][3] > arr_dcs[arr_i][3]){
         time_output = arr_IdSample[i][3];
      }else {
         time_output = arr_dcs[arr_i][3];
      }

      cout << "[  " << "����������� ������� ��� ������� ID[" << arr_dcs[arr_i][0] << "] --> �������� ID [" << arr_IdSample[i][0] << "] --> ������ ID[" << arr_IdSample[i][1] << "] --> ����� �������: " << time_output + time_wp << " ���.  ]" << endl; 
      cout << "[-------------------" << "-------------------" << "-------------------" << "-------------------" << "-------------------" << "-------------------]" << endl; //50 "-------------------"
   }
}
