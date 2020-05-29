#include <iostream>
#include <math.h>

using namespace std;

int main() {
int i, j, row=5, colomn=2;
float katet1, katet2;
   float dolg_klient=55.326598;
   float shir_klient=65.321456;
float studio[row][colomn];
float photograph[row][colomn];
float visagiste[row][colomn];
float rastoyanye_kl_st[row];
   float rastoyanye_st_viz[row][colomn];
   float rastoyanye_st_fot[row][colomn];
//заполняем массивы
studio[0][0]=65.554210;
studio[0][1]=62.455221;
studio[1][0]=55.323659;
studio[1][1]=62.256482;
studio[2][0]=62.523641;
studio[2][1]=61.564896;
studio[3][0]=58.569874;
studio[3][1]=62.561203;
studio[4][0]=57.569874;
studio[4][1]=62.555441;
photograph[0][0]=62.124511;
photograph[0][1]=65.811111;
photograph[1][0]=62.122222;
photograph[1][1]=60.822222;
photograph[2][0]=60.889551;
photograph[2][1]=64.369852;
photograph[3][0]=68.269458;
photograph[3][1]=60.562103;
photograph[4][0]=62.562031;
photograph[4][1]=69.995511;
visagiste[0][0]=68.856893;
visagiste[0][1]=61.856525;
visagiste[1][0]=66.845652;
visagiste[1][1]=61.877854;
visagiste[2][0]=63.561234;
visagiste[1][1]=66.232323;
visagiste[3][0]=69.841252;
visagiste[3][1]=66.879154;
visagiste[4][0]=69.235697;
visagiste[4][1]=67.822001;
//считаем сколько клиенту нужно чтобы добраться до студии
for (i=0; i < row; i++){
   katet1=fabs(studio[i][0]-dolg_klient);
katet2=fabs(studio[i][1]-shir_klient);
rastoyanye_kl_st[i]=sqrt(pow(katet1,2)+pow(katet2,2));
}

for (i=0; i < row; i++){
   
cout<<"Расстояние от клиента до "<<i+1<<"-й студии = "<<rastoyanye_kl_st[i]<<" км"<<endl;
   
}
cout<<endl;
//считаем сколько визажисту нужно чтобы добраться до студии
for (i=0; i < row; i++){
   for (j=0;j<row; j++){
   katet1=fabs(studio[i][0]-visagiste[j][0]);
katet2=fabs(studio[i][1]-visagiste[j][1]);
rastoyanye_st_viz[i][j]=sqrt(pow(katet1,2)+pow(katet2,2));
}
}
for (i=0; i < row; i++){
   for (j=0; j < row; j++){
   
cout<<"Расстояние от" <<i+1<<"-й студии до "<<j+1<<"-ого визажиста = "<<rastoyanye_st_viz[i][j]<<" км"<<endl;
   
}
}
cout<<endl;
//считаем сколько фотографу нужно чтобы добраться до студии
for (i=0; i < row; i++){
   for (j=0;j<row; j++){
   katet1=fabs(studio[i][0]-photograph[j][0]);
katet2=fabs(studio[i][1]-photograph[j][1]);
rastoyanye_st_fot[i][j]=sqrt(pow(katet1,2)+pow(katet2,2));
}
}
for (i=0; i < row; i++){
   for (j=0; j < row; j++){
   
cout<<"Расстояние от" <<i+1<<"-й студии до "<<j+1<<"-ого фотографа = "<<rastoyanye_st_fot[i][j]<<" км"<<endl;
   
}
}
cout<<endl;
/*katet1=fabs(studio[1][1]-photograph[1][1]);
katet2=fabs(studio[1][2]-photograph[1][2]);
rast=sqrt(pow(katet1,2)+pow(katet2,2));
cout<<rast<<endl;*/
return 0;
}