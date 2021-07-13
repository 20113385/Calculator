using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProjectMahasiswa
{
    class Program
    {
        // deklarasi objek collection untuk menampung objek mahasiswa
        static List<Mahasiswa> daftarMahasiswa = new List<Mahasiswa>();

        static void Main(string[] args)
        {
            Console.Title = "Responsi UAS Matakuliah Pemrograman";

            while (true)
            {
                TampilMenu();

                Console.Write("\nNomor Menu [1..4]: ");
                int nomorMenu = Convert.ToInt32(Console.ReadLine());

                switch (nomorMenu)
                {
                    case 1:
                        TambahMahasiswa();
                        break;

                    case 2:
                        HapusMahasiswa();
                        break;

                    case 3:
                        TampilMahasiswa();
                        break;

                    case 4: // keluar dari program
                        return;

                    default:
                        break;
                }
            }
        }

        static void TampilMenu()
        {
            Console.Clear();

            // PERINTAH: lengkapi kode untuk menampilkan menu

            Console.WriteLine("Pilih Menu Aplikasi");
            Console.WriteLine("1. Tambah Mahasiswa");
            Console.WriteLine("2. Hapus Mahasiswa");
            Console.WriteLine("3. Tampilkan Mahasiswa");
            Console.WriteLine("4. Keluar");
            
        }

        static void TambahMahasiswa()
        {
            Console.Clear();

            // PERINTAH: lengkapi kode untuk menambahkan objek mahasiswa ke dalam collection

            string nim;
            string nama;
            string jeniskelamin;
            string ipk;

            Console.Write("NIM: ");
            nim = Console.ReadLine();
            Console.Write("Nama:");
            nama = Console.ReadLine();
            Console.Write("Jenis Kelamin:");
            jeniskelamin = Console.ReadLine();

            if (jeniskelamin.Equals("P", StringComparison.InvariantCultureIgnoreCase))
            {
                jeniskelamin = "Perempuan";
            }
            else
            {
                jeniskelamin = "Laki-Laki";
            }

            Console.Write("IPK:");
            ipk = Console.ReadLine();

            daftarMahasiswa.Add(new Mahasiswa(nim, nama, jeniskelamin, ipk));

            Console.WriteLine("\nTekan ENTER untuk kembali ke menu");
            Console.ReadKey();
        }

        static void HapusMahasiswa()
        {
            Console.Clear();

            // PERINTAH: lengkapi kode untuk menghapus objek mahasiswa dari dalam collection
            string pencarian;
            Console.WriteLine("Hapus data mahasiswa \n");


            Console.WriteLine("NIM: ");
            pencarian = Console.ReadLine();

            int indexdata = daftarMahasiswa.FindIndex(data => data.nim.Equals(pencarian));

            if (indexdata == -1)
            {
                Console.WriteLine("NIM tidak ditemukan");
            }
            else {
                daftarMahasiswa.RemoveAt(indexdata);
                Console.WriteLine("Data mahasiswa berhail dihapus");
            }

            Console.WriteLine("\nTekan ENTER untuk kembali ke menu");
            Console.ReadKey();
        }

        static void TampilMahasiswa()
        {
            Console.Clear();

            // PERINTAH: lengkapi kode untuk menampilkan daftar mahasiswa yang ada di dalam collection
            Console.WriteLine("Daftar Mahasiswa: /n");

            int jumlah = 1;
            foreach(var mahasiswa in daftarMahasiswa)
            {
                Console.WriteLine("{0}. {1}, {2}, {3}, {4}", jumlah, mahasiswa.nim, mahasiswa.nama, mahasiswa.jeniskelamin, mahasiswa.ipk);
                jumlah++;
            }

            Console.WriteLine("\nTekan enter untuk kembali ke menu");
            Console.ReadKey();
        }
    }
}