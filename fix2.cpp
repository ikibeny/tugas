#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;



struct  mobil{
        int jumlah_antrian; //untuk kepala saja
        char nama[30];
        char plat[30];
        void print_info(){
            cout<<"\t\t "<<nama<<"    \t "<<plat<<endl;
        };
        void print_infoo(){
            cout<<nama<<"    \t "<<plat<<endl;
        };
        mobil *next;
};


mobil *kepala, *ekor;


void buat_queue(){

      kepala = new mobil();
      kepala->jumlah_antrian = 0;

}

bool queueIsEMpety(){
    return (kepala->jumlah_antrian == 0);
    };

void enque(mobil *data){

    if(queueIsEMpety()){
            kepala -> next = ekor = data;

    }else{
        ekor->next = data;
        ekor = data;
    }

    kepala->jumlah_antrian++;
}


mobil *edit(int posisi){

        mobil *bantu = kepala;
        while(posisi--) bantu = bantu->next;
        return bantu;

};



mobil * deque(){
        mobil *hasil = kepala;
        kepala = kepala->next;
        kepala->jumlah_antrian--;
        return hasil;
}


void baca(){
        mobil *bantu = kepala ->next;
        int i = 0;
       while(bantu != NULL){
         cout<< ++i << ". ";bantu->print_info();
        bantu = bantu->next;
       }
}



void  sorting(){


    //create copy of data;
    int jumlahData = kepala->jumlah_antrian;
    mobil *data[jumlahData];
    mobil *bantu = kepala;
    for(int i = 0; i<jumlahData; i++ ){
        data[i] = bantu->next;
        bantu = bantu->next;
    }




    // sort dengan bubble sort

    for(int i  = 0 ; i< jumlahData; i++){
        for(int j = 0 ; j < jumlahData -1 ; j++){

            if(strcmp(data[j]->nama,data[j+1]->nama)> 0 )
                swap(data[j],data[j+1]);
        }
    }


    //print atau cetak


    for(int i = 0; i<jumlahData; i++ ){
        cout<< i +1 <<". ";data[i]->print_info();
    }





}

void cari(char target[30]){


    mobil *bantu = kepala;
    bool found;
    while((bantu= bantu->next) != NULL)
        if(strcmp(target,bantu->nama)==0){
                    found = true;
                    break;
        }


    if(found)
        bantu->print_infoo();
    else
        cout<<target<<" tidak ada dalam antrian"<<endl;





}


void input(){
        int num;
        mobil *tmp = new mobil();
        cout<<"Nama mobil : ";cin>>tmp->nama;
        cout<<"Nomor plat : ";cin>>tmp->plat;
        enque(tmp);

}



void edit(){

    int num;
    cout<<"masukan nomor antrian : ";cin>>num;
    mobil *bantu = kepala;
    if(num < kepala->jumlah_antrian || num > kepala->jumlah_antrian){
                cout<<"Nomor antrian salah \n"<<endl;
    }
    else{
    while(num--)
        bantu = bantu->next;

    cout<<"data antrian : "<<endl;
    bantu->print_info();
    cout<<"masukan ulang nama : ";cin>>bantu->nama;
    cout<<"masukan ulang plat : ";cin>>bantu->plat;
    }
}



int main(){
    buat_queue();
    int menu;
    char yn = 'y';
    cout<<"\t\t========------------------=========\n";
    cout<<"\t\t========Beny-Galuh-Al-Ompa=========\n";
	cout<<"\t\t========------------------=========\n";
    cout<<"\t\t======ANTRIAN BENGKEL MOBIL========\n";
	cout<<"\t\t===================================\n";
    cout<<"\t\t|              Menu               |\n";
    cout<<"\t\t===================================\n";
    do{
    cout<<"\tPILIH: "<<endl;
    cout<<"\t1. Input antrian Mobil "<<endl;
    cout<<"\t2. Layani antrian pertama "<<endl;
    cout<<"\t3. Lihat Antrian "<<endl;
    cout<<"\t4. Cari antrian [berdasarkan nama mobil] "<<endl;
    cout<<"\t5. sorting [Berdasarkan Nama Mobil]"<<endl;
    cout<<"\t6. Edit Data [Berdasarkan No Urut] "<<endl;
    cout<<"\t7. Hapus semua data"<<endl;
    cout<<"\tMasukan pilihan : ";cin>>menu;
    cout<<endl;

    switch(menu){
    case 1  :
        input();
        cout<<"kembali ke menu utama ? <y/n>";cin>>yn;
        cout<<endl;
    break;
    case 2 :
        cout<<"sukses layani antrian pertama! "<<endl;
        deque()->print_info();
        cout<<"kembali ke menu utama ? <y/n>";cin>>yn;
    	cout<<endl;
	break;
    case 3:
    	cout<<"[NO urut]\t [MOBIL] \t [PLAT NO] "<<endl<<endl;
        if(!queueIsEMpety()) baca(); else cout<<"antrian masih kosong "<<endl;
        cout<<"kembali ke menu utama ? <y/n>";cin>>yn;
        cout<<endl;
    break;
    case 4:
        char nama[30];
        cout<<"masukan nama mobil yang dicari :";cin>>nama;
    	cout<<"[MOBIL] \t [PLAT NO] "<<endl<<endl;
        cari(nama);
        cout<<"kembali ke menu utama ? <y/n>";cin>>yn;
        cout<<endl;
    break;
    case 5:
    	cout<<"[NO urut]\t [MOBIL] \t [PLAT NO] "<<endl<<endl;
        sorting();
        cout<<"kembali ke menu utama ? <y/n>";cin>>yn;
        cout<<endl;
    break;
    case 6:
        int nomor;
        cout<<"Masukan nomer antrian : ";cin>>nomor;
        edit(nomor)->print_info();
        if(nomor > 0 && nomor <=kepala->jumlah_antrian){
            cout<<"masukan ulang nama : ";cin>>edit(nomor)->nama;
            cout<<"masukan ulang plat : ";cin>>edit(nomor)->plat;
            cout<<"sukses update bos !"<<endl;
        }else{
            cout<<"nomor antrian salah";
        }
        cout<<"kembali ke menu utama ? <y/n>";cin>>yn;
        cout<<endl;
    break;
    case 7:
        buat_queue();
        cout<<"SUKSES HAPUS DATA SEMUA\n";
        cout<<"kembali ke menu utama ? <y/n>";cin>>yn;
    break;

    }
    }while(yn == 'y');



}





