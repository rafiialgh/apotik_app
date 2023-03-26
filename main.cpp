#include <iostream>
#include <string>
using namespace std;
int i = 1;

class obat
{
  // friend class dan friend function
  friend void persediaan_obat(obat &);
  friend int cari_data(obat &, string a);
  friend class detail_pembelian;

private:
  string id;
  string nama_barang;
  int harga_barang;
  int stock;
  int stock_awal;

  // Constructor overloading
public:
  obat() {}
  obat(string id, string nama_barang, int harga_barang, int stock)
  {
    this->id = id;
    this->nama_barang = nama_barang;
    this->harga_barang = harga_barang;
    this->stock = stock;
    this->stock_awal = stock;
  }

  // Update sisa stock
  int reduction(int jumlah)
  {
    stock = stock - jumlah;
    cout << "sisa stock = " << stock << endl
         << endl;
    return 0;
  }

  // menampilkan harga jual total tiap barang
  void penjualan()
  {
    int s = 0;
    s = (stock_awal - stock) * harga_barang;
    cout << endl
         << "harga obat yang telah terjual : " << s << endl
         << endl;
  }
};

class detail_pembelian
{
public:
  string name;
  string address;
  int id_pembelian;
  string code_obat;
  int jumlah_pembelian;
} pembelian[99];

void menu()
{
  cout << "menu : (pilih dari character yang disediakan)" << endl;
  cout << "a. persediaan obat beserta harga" << endl;
  cout << "b. penjualan obat yang meliputi obat dan jumlah, serta harga" << endl;
  cout << "c. pejualan berdasarkan resep dokter" << endl;
  cout << "d. cetak kwitansi penjualan" << endl;
  cout << "e. keluar" << endl;
  cout << "pilihan : ";
}

// menampilkan data ketersediaan obat
void persediaan_obat(obat &data)
{
  cout << data.id << "\t" << data.nama_barang << "\t" << data.harga_barang << "\t" << data.stock << endl;
}
int cari_data(obat &data, string a)
{
  if (a == data.id)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// menampilkan jumlah produk yang akan dibeli
int input_jumlah()
{
  int temp;
  cout << "input jumlah barang yang ingin di beli : ";
  cin >> temp;
  return temp;
}

// menampilkan data nama, harga, dan jumlah
void header()
{
  cout << endl;
  cout << "code \tnama \tharga \tjumlah \n";
}

// code penjualan berdasarkan resep dokter
void transaksi(string x, int y, int z)
{
  pembelian[i].code_obat = x;
  pembelian[i].jumlah_pembelian = y;
  pembelian[i].id_pembelian = i;
  if (z == 0)
  {
    pembelian[i].name = " ";
    pembelian[i].address = " ";
  }
  else
  {
    cout << "masukkan nama pembeli :";
    cin >> pembelian[i].name;
    cout << "masukkan address pembeli :";
    cin >> pembelian[i].address;
    cout << endl;
    cout << "id pembelian \tnama \talamat \tjumlah_pembelian\n";
    cout << pembelian[i].id_pembelian << "\t\t" << pembelian[i].name << "\t" << pembelian[i].address << "\t" << pembelian[i].jumlah_pembelian << endl
         << endl;
  }
  i++;
}

// cetak transaksi penjualan obat berdasarkan resep dokter
void print_transaksi(obat &data, string x)
{
  int a;
  header();
  persediaan_obat(data);
  cout << "id pembelian \tnama \talamat \tjumlah_pembelian\n";
  for (a = 0; a <= i; a++)
    if (x == pembelian[a].code_obat)
    {
      cout << pembelian[a].id_pembelian << "\t\t" << pembelian[a].name << "\t" << pembelian[a].address << "\t" << pembelian[a].jumlah_pembelian << endl
           << endl;
    }
    else
    {
      continue;
    }
}

int main()
{
  char selection;
  string code_obat;
  int jumlah;

  // Constructor overloading
  obat data1("OBT001", "Panadol", 10000, 13);
  obat data2("OBT002", "Sanmol", 15000, 18);
  obat data3("OBT003", "Bodrex", 11000, 25);

  do
  {
    menu();
    cin >> selection;
    // percabangan dalam pemilihan produk berdasarkan kode produk
    switch (selection)
    {
    case 'a':
      header();
      persediaan_obat(data1);
      persediaan_obat(data2);
      persediaan_obat(data3);
      cout << endl;
      break;
    case 'b':
      cout << "masukan code (CAPITAL) : ";
      cin >> code_obat;

      if (cari_data(data1, code_obat) == true)
      {
        header();
        persediaan_obat(data1);
        cout << endl;
        jumlah = input_jumlah();
        data1.reduction(jumlah);
        transaksi(code_obat, jumlah, 0);
      }
      else if (cari_data(data2, code_obat) == true)
      {
        header();
        persediaan_obat(data2);
        cout << endl;
        jumlah = input_jumlah();
        data2.reduction(jumlah);
        transaksi(code_obat, jumlah, 0);
      }
      else if (cari_data(data3, code_obat) == true)
      {
        header();
        persediaan_obat(data3);
        cout << endl;
        jumlah = input_jumlah();
        data3.reduction(jumlah);
        transaksi(code_obat, jumlah, 0);
      }

      else
      {
        cout << endl
             << "tidak ada obat yang memiliki code tersebut" << endl
             << endl;
      }
      break;
    case 'c':
      cout << "masukan code (CAPITAL) : ";
      cin >> code_obat;

      if (cari_data(data1, code_obat) == true)
      {
        header();
        persediaan_obat(data1);
        cout << endl;
        jumlah = input_jumlah();
        data1.reduction(jumlah);
        transaksi(code_obat, jumlah, 1);
      }
      else if (cari_data(data2, code_obat) == true)
      {
        header();
        persediaan_obat(data2);
        cout << endl;
        jumlah = input_jumlah();
        data2.reduction(jumlah);
        transaksi(code_obat, jumlah, 1);
      }
      else if (cari_data(data3, code_obat) == true)
      {
        header();
        persediaan_obat(data3);
        cout << endl;
        jumlah = input_jumlah();
        data3.reduction(jumlah);
        transaksi(code_obat, jumlah, 1);
      }
      break;
    case 'd':
      cout << "masukan code (CAPITAL) : ";
      cin >> code_obat;

      if (cari_data(data1, code_obat) == true)
      {
        print_transaksi(data1, code_obat);
        data1.penjualan();
      }
      else if (cari_data(data2, code_obat) == true)
      {
        print_transaksi(data2, code_obat);
        data2.penjualan();
      }
      else if (cari_data(data3, code_obat) == true)
      {
        print_transaksi(data3, code_obat);
        data3.penjualan();
      }
      break;
      // Exit program
    case 'e':
      cout << "terimakasih" << endl
           << endl;
    default:
      cout << endl
           << "code yang dimasukkan tidak tersedia" << endl
           << endl;
    }
  } while (selection != 'e');

  return 0;
}