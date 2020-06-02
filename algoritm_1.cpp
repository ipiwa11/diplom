#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std; 

double distance_to(double d_lagitude, double d_longitude, double a_lagitude, double a_longitude, int average_speed){
   //d_lagitude, a_lagitude - Ширина отправления/назначения
   //d_longitude, a_longitude - Долгота отправления/назначения
   
   int katet_1, katet_2;
   double value_return = 0;
   
   katet_1 = fabs(d_lagitude - a_lagitude);
   katet_2 = fabs(d_longitude - a_longitude);
   
   if (average_speed == 0){
      value_return = sqrt(pow(katet_1, 2) + pow(katet_2, 2)); //Если скорость не задана или если нужно узнать только расстояние
   } 
   else if(average_speed > 0){
      value_return = sqrt(pow(katet_1, 2) + pow(katet_2, 2)) / average_speed * 60;//Если скорость задана и нужно посчитать время
   }
   
   return value_return; // Расстояние/Время
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
   double arr_studio[row][3], arr_photograph[row][3], arr_client[1][3]; //Структура таблицы 
                                                                                                            //КОЛОНКИ: [0] - ID(Идентификатор), [1] - latitude(Широта), [2] - longtitude(Долгота)
   cout << endl << "<<<Блок студии>>>" << endl << endl;
   //Блок студии
   for(i = 0; i < row; i++){
        arr_studio[i][0] = i + 1;//Задаем идентификатор каждой студии   
      }
   
   for (i = 0; i < row; i++){
      arr_studio[i][1] = matrix_value();//Ширина студии
      arr_studio[i][2] = matrix_value();//Долгота студии
      cout << "Студия ID[" << arr_studio[i][0] << "]: Широта = " << setprecision(8) << arr_studio[i][1] << " | Долгота = " << arr_studio[i][2] << endl;
   }
   //КонецБлока
   cout << endl << "<<<Блок фотографы>>>" << endl << endl;
   //Блок фотограф
   for(i = 0; i < row; i++){
        arr_photograph[i][0] = i + 1;//Задаем идентификатор каждому фотографу
   }
   
   for (i = 0; i < row; i++){
      arr_photograph[i][1] = matrix_value();//Ширина фотографа
      arr_photograph[i][2] = matrix_value();//Долгота фотографа
      cout << "Фотограф ID[" << arr_photograph[i][0] << "]: Широта = " << setprecision(8) << arr_photograph[i][1] << " | Долгота = " << arr_photograph[i][2] << endl;
   }
   //КонецБлока
   cout << endl << "<<<Блок клиент>>>" << endl << endl;
   //Блок клиент
   for(i = 0; i < 1; i++){
        arr_client[i][0] = i + 1;//Задаем идентификатор каждому фотографу
   }
   
   for (i = 0; i < 1; i++){
      arr_client[i][1] = matrix_value();//Ширина фотографа
      arr_client[i][2] = matrix_value();//Долгота фотографа
      cout << "Клиент ID[" << arr_client[i][0] << "]: Широта = " << setprecision(8) << arr_client[i][1] << " | Долгота = " << arr_client[i][2] << endl;
   }
   //КонецБлока
   cout << endl << "<<<Блок расчетов>>>" << endl << endl;
   //------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
   
   //------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   //Блок расчет расстояния
   int size_dps = row * row;
   double arr_dcs[row][colomn]; //arr_distance_from_client_to_studio //Расстояние от клиента до студии
//   double arr_dps[size_dps] [colomn]; //arr_distance_from_photograph_to_studio //Расстояние от фотографа до студии
   /*
            Структура таблицы (Матрицы)
    [0] - ID Клиента/Фотографа|| [1] - ID Студии || [2] - Расстояние от клиента до студии || [3] - Время от клиента до студии ||
    Имена колонок зависят от адресата отправления (от Клиента/Фотографа до Студии)
    */
   //Расстояние и время от клиента до студии
   int count = 0;
      
   for(i = 0; i < 1; i++){
      for(j =0; j < row; j++){
         arr_dcs[count][0] = arr_client[i][0];
         arr_dcs[count][1] = arr_studio[j][0];
         arr_dcs[count][2] = distance_to(arr_client[i][1], arr_client[i][2], arr_studio[j][1], arr_studio[j][2], 0);
         arr_dcs[count][3] = distance_to(arr_client[i][1], arr_client[i][2], arr_studio[j][1], arr_studio[j][2], average_speed);
         //Вывод данных напрямую
         cout << setprecision(2) << "ID Клиента [" << arr_dcs[count][0] << "] ID Студии [" << arr_dcs[count][1] << "] Расстояние (км): " << arr_dcs[count][2] << " Время (мин): " << arr_dcs[count][3] << endl; 
         count ++;
      }
      cout << "[---------------------------------------------------------------------]" << endl;
   }
   
   count = 0;

   double time_crts = 0, //time_client_ready_to_spend //Время, которое клиент готов потратить на услугу (мин)
               time_wp = 60.0; //time_work_photograph //Время работы фотографа (Единое для всех) (мин)
   
   cout << endl << "Введите время, которое клиент готов потратить на услугу (мин): "; 
   //time_crts = 80;
  // cin >> time_crts;
   
   //ОБРАБОТЧИК ОШИБКИ ОБ ОТСУТСВИИ ПОДХОДЯЩИХ СТУДИЙ,
   // А ТАКЖЕ О СЛИШКОМ МАЛЕНЬКОМ ПРОМЕЖУТКЕ ВРЕМЕНИ
    double time_rm; //Остаточное время = Время которое клиент готов потратить - Время работы фотографа
      
   bool flag=true;
   while(flag){
      flag = false;
      cin >> time_crts;
   
      time_rm = time_crts - time_wp;
      
      if(time_rm <= 0){
         cout << endl << "Ошибка! Указан слишком маленький промежуток времени" << endl;
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
            cout << "Ошибка, нет подходящих студий" << endl;
            cout << endl << "Введите время, которое клиент готов потратить на услугу (мин): ";
         }
   }
         
         
   vector <int> arr_idSort;   
   for(i = 0; i < row; i++){
      if(arr_dcs[i][3] < time_rm){
         arr_idSort.push_back(i);//Т.к. 1 клиент, без разницы какой индекс добавлять в массив
      }
   }
   int size_sort_arr_id = 0, size_arr_phot = 0;
   size_sort_arr_id = arr_idSort.size();
   size_arr_phot = (sizeof(arr_photograph) / sizeof(arr_photograph[0]));
   int size_arrIS = size_arr_phot * size_sort_arr_id;
   double arr_IdSample[size_arrIS][colomn]; //Создаем новый массив, в который будем переносить все строки
   
   cout << endl;
   
   //Рассчитаем расстояние и время от каждого фотографа (первый цикл) до каждой выбранной (отбором) студий (вложенный цикл)
   for(i = 0; i < size_arr_phot; i++){
      for(j =0; j < size_sort_arr_id; j++){
         arr_IdSample[count][0] = arr_photograph[i][0]; //Идентификатор фотографа
         arr_IdSample[count][1] = arr_studio[arr_idSort[j]][0]; //Идентфикиатор студии
         arr_IdSample[count][2] = distance_to(arr_photograph[i][1], arr_photograph[i][2], arr_studio[arr_idSort[j]][1], arr_studio[arr_idSort[j]][2], 0); //Расчет дистанции
         arr_IdSample[count][3] = distance_to(arr_photograph[i][1], arr_photograph[i][2], arr_studio[arr_idSort[j]][1], arr_studio[arr_idSort[j]][2], average_speed); //Расчет времени
         //Вывод данных напрямую
         cout << setprecision(2) << "ID Фотографа [" << arr_IdSample[count][0] << "] ID Студии [" << arr_IdSample[count][1] << "] Расстояние (км): " << arr_IdSample[count][2] << " Время (мин): " << arr_IdSample[count][3] << endl; 
         count++;
      }
      cout << "[---------------------------------------------------------------------]" << endl;
   }
   
   count = 0;
   //Сортировка фотографов по возрастанию, от того, кто быстрее доедет до студии
   //до последнего
   
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
   
   cout << endl << "[--------------- Конечный отсортированный массив фотографов ---------------]" << endl;
    
    for(i = 0; i < 3; i++){
      cout << setprecision(2) << "ID Фотографа [" << arr_IdSample[i][0] << "] ID Студии [" << arr_IdSample[i][1] << "] Расстояние (км): " << arr_IdSample[i][2] << " Время (мин): " << arr_IdSample[i][3] << endl; 
    }
    
   cout << endl << "[---------------------------------- Построенная цепочка ----------------------------------]" << endl << endl;
   
   double time_output = 0;
 // ВЫВОД ГОТОВЫХ ЦЕПОЧЕК КЛИЕНТУ   
   for(i = 0; i < 3; i++){
      int arr_i = arr_IdSample[i][1] - 1;
      cout << endl << "ФОТОГРАФ ВРЕМЯ: " << arr_IdSample[i][3] << " КЛИЕНТ ВРЕМЯ: " << arr_dcs[arr_i][3] << " ID Студии: " << arr_dcs[arr_i][1] << endl;
      if(arr_IdSample[i][3] > arr_dcs[arr_i][3]){
         time_output = arr_IdSample[i][3];
      }else {
         time_output = arr_dcs[arr_i][3];
      }

      cout << "[  " << "Оптимальный вариант для клиента ID[" << arr_dcs[arr_i][0] << "] --> Фотограф ID [" << arr_IdSample[i][0] << "] --> Студия ID[" << arr_IdSample[i][1] << "] --> Время цепочки: " << time_output + time_wp << " мин.  ]" << endl; 
      cout << "[-------------------" << "-------------------" << "-------------------" << "-------------------" << "-------------------" << "-------------------]" << endl; //50 "-------------------"
   }
}
