#include<iostream>
using namespace std;
#include<string>
#include<cmath>

int Chuyen_Chuoi_Thanh_So_Nguyen(string s);
string Cong_2_SO_Nguyen_Cung_Duong(string x, string y);
string Cong_2_SO_Nguyen_Cung_Am(string x, string y);
string Cong_2_So_Nguyen_Trai_Dau(string x, string y);
string Tru_2_So_Duong(string x, string y);
string Cong(string x, string y, string pheptinh);
int Do_Dai_Chuoi_So(string x, string y);
void Them_Dau_Cham_Vao_So(string &kq);
void Phep_CHia(string x, string y);
void LamTronPhepChia(string &x, string &y);
void Nhan_2_So_Cung_Dau(string x, string y);

// dem so luong phan tu co trong so
int DemSo(int x)
{
	int dem = 0;
	while (x > 0)
	{
		dem++;
		x = x / 10;
	}
	return dem;
}
int Chuyen_Chuoi_Thanh_So_Nguyen(string s)
{
	int x = 0;
	int mu = 0;
	int len = s.length();
	if (s.at(0) == '-')
	{
		for (int i = len - 1; i > 0; i--)
		{
			x = x + (s[i] - 48) * pow(10, mu);
			mu++;
		}
		return -x;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		x = x + (s[i] - 48) * pow(10, mu);
		mu++;
	}
	return x;
}
string Cong_2_SO_Nguyen_Cung_Duong(string x, string y)
{
	
	int i = x.length() - 1;
	int j = y.length() - 1;
	string kq = "";
	int dem = 0;
	int nho = 0;
	while (i >= 0 || j >= 0)
	{
		int s = 0;
		if (i < 0) // x h?t ph?n t? 
		{
			s = (y[j] - 48) + nho;
		}
		else if (j < 0) // y h?t ph?n t?
		{
			s = (x[i] - 48) + nho;
		}
		else  // c? x và y ??u còn ph?n t?
		{
			s = (x[i] - 48) + (y[j] - 48) + nho;
		}
		if (s < 10)
		{
			kq.insert(kq.begin() + 0, s + 48);
			nho = 0;
		}
		else if (s >= 10)
		{
			int du = s % 10;
			kq.insert(kq.begin() + 0, du + 48);
			nho = 1;
		}
		i--;
		j--;
	}
	if (nho != 0)
	{
		kq.insert(kq.begin() + 0, nho + 48);
	}
	return kq;
}
string Cong_2_SO_Nguyen_Cung_Am(string x, string y)
{
	x.erase(x.begin() + 0);
	y.erase(y.begin() + 0);
	int i = x.length() - 1;
	int j = y.length() - 1;
	string kq = "";
	int dem = 0;
	int nho = 0;
	while (i >= 0 || j >= 0)
	{
		int s = 0;
		if (i < 0) // x h?t ph?n t? 
		{
			s = (y[j] - 48) + nho;
		}
		else if (j < 0) // y h?t ph?n t?
		{
			s = (x[i] - 48) + nho;	
		}
		else  // c? x và y ??u còn ph?n t?
		{
			s = (x[i] - 48) + (y[j] - 48) + nho;
		}
		if (s < 10)
		{
			kq.insert(kq.begin() + 0, s + 48);
			nho = 0;
		}
		else if (s >= 10)
		{
			int du = s % 10;
			kq.insert(kq.begin() + 0, du + 48);
			nho = 1;
		}
		i--;
		j--;
	}
	if (nho != 0)
	{
		kq.insert(kq.begin() + 0, nho + 48);
	}
	kq.insert(kq.begin() + 0, '-');
	return kq;
}
// c?ng 2 s? nguyên trái d?u tr??ng h?p s? âm l?n h?n s? d??ng
string Cong_2_So_Nguyen_Trai_Dau(string x, string y)
{
	string so_am;
	string so_duong;
	if (x.at(0) == '-')
	{
		so_am = x;
		so_duong = y;
	}
	else
	{
		so_am = y;
		so_duong = x;
	}
	int i = so_am.length() - 1;
	int j = so_duong.length() - 1;
	int s;
	int nho = 0;
	string kq = "";
	while (i > 0 || j >= 0)
	{
			if (j >= 0)
			{
				if ((so_am[i] - 48) >= (so_duong[j] - 48) + nho)
				{
					s = (so_am[i] - 48) - (so_duong[j] - 48) - nho;
					nho = 0;
				}
				else
				{
					s = 10 + (so_am[i] - 48) - (so_duong[j] - 48) - nho;
					nho = 1;
				}
			}
			else
			{
				s = (so_am[i] - 48) - nho;
				nho = 0;
			}
					
		
		// ========== ti?n hành ??a vào chu?i ===========
		kq.insert(kq.begin() + 0, s + 48);
		i--;
		j--;
	}
	if (kq[0] == '0')
	{
		kq.erase(kq.begin() + 0);
	}
	kq.insert(kq.begin() + 0, '-');
	return kq;
}
// tr??ng h?p hai s? nguyên ??u d??ng và x > y
string Tru_2_So_Duong(string x, string y)
{
	int i = x.length() - 1;
	int j = y.length() - 1;
	string kq = "";
	int s;
	int nho = 0;
	while (i >= 0 || j >= 0)
	{
		if (j < 0) // y ?ã h?t s?
		{
			s = (x[i] - 48) - nho;
			nho = 0;
		}
		else // y còn s?
		{
			if ((x[i] - 48) >= ((y[j] - 48) + nho))
			{
				s = (x[i] - 48) - (y[j] - 48) - nho;
				nho = 0;
			}
			else
			{
				s = 10 + (x[i] - 48) - (y[j] - 48) - nho;
				nho = 1;
			}
		}
		kq.insert(kq.begin() + 0, s + 48);
		i--;
		j--;
	}
	while (kq[0] == '0')
	{
		kq.erase(kq.begin() + 0);
	}
	return kq;
}
// hàm so sánh ?? dài chu?i(tr? tuy?t ??i c?a s? ?ó)

int Do_Dai_Chuoi_So(string x, string y)
{
	// ======== Tr? tuy?t ??i chu?i s? ===========
	if (x[0] == '-')
		x.erase(x.begin() + 0);
	if (y[0] == '-')
		y.erase(y.begin() + 0);
	// ======== ki?m tra ?? dài chu?i sô ===========
	if (x.length() > y.length()) // tr? v? 1 n?u chu?i x l?n h?n
		return 1;
	else if (x.length() < y.length()) // tr? v? -1 n?u chu?i y l?n h?n
		return -1;
	else if (x.length() == y.length())
	{
		return strcmp(x.c_str(), y.c_str());
	}
}
// chu?n hoá s? có d?u ch?m theo phong cách calculator
void Them_Dau_Cham_Vao_So(string &kq)
{
	int dem = 0;
	if (kq[0] == '-')
	{
		for (int i = kq.length() - 1; i > 1; i--)
		{
			dem++;
			if (dem % 3 == 0 && dem != 0)
			{
				kq.insert(kq.begin() + i, '.');
			}
		}
	}
	else
	{
		for (int i = kq.length() - 1; i > 0; i--)
		{
			dem++;
			if (dem % 3 == 0 && dem != 0)
			{
				kq.insert(kq.begin() + i, '.');
			}
		}
	}
}
string Cong(string x, string y,string pheptinh)
{
	if (pheptinh == "+")
	{
		// tr??ng h?p 1: a và b ??u d??ng , phép tính là c?ng
		if (x[0] != '-' && y[0] != '-')
		{
			string kq = Cong_2_SO_Nguyen_Cung_Duong(x, y);
			Them_Dau_Cham_Vao_So(kq);
			return kq;
		}
		// tr??ng h?p 2: c?ng 2 s? âm
		else if (x[0] == '-' && y[0] == '-')
		{
			string kq = Cong_2_SO_Nguyen_Cung_Am(x, y);
			Them_Dau_Cham_Vao_So(kq);
			return kq;
		}
		// tr??ng h?p 3 c? 2 s? trái d?u
		else
		{
			// n?u 2 chu?i s? b?ng nhau thì tr? v? 0
			if (Do_Dai_Chuoi_So(x, y) == 0)
			{
				string kq = "0";
				return kq;
			}
			// chu?i x l?n h?n chu?i y
			else if (Do_Dai_Chuoi_So(x, y) > 0)
			{
				// tr??ng h?p x là s? âm và y là s? d??ng và ?? dài chu?i x l?n h?n chu?i y (giá tri tuy?t ??i)
				if (x[0] == '-')
				{
					string kq = Cong_2_So_Nguyen_Trai_Dau(x, y);
					Them_Dau_Cham_Vao_So(kq);
					return kq;
				}
				// tr??ng h?p x là s? d??ng y là s? âm thì chuy?n vê d?ng tr? 2 s? d??ng
				else
				{
					y.erase(y.begin() + 0);
					string kq = Tru_2_So_Duong(x, y);
					Them_Dau_Cham_Vao_So(kq);
					return kq;
				}
			}
			// ?? dài chu?i y l?n h?n chu?i x
			else
			{
				if (x[0] == '-')
				{
					x.erase(x.begin() + 0);
					string kq = Tru_2_So_Duong(y,x);
					Them_Dau_Cham_Vao_So(kq);
					return kq;
				}
				else
				{
					string kq = Cong_2_So_Nguyen_Trai_Dau(x, y);
					Them_Dau_Cham_Vao_So(kq);
					return kq;
				}
			}
		}
	}
}
// neu co dau ',' thi xoa dau , nhan them 10^mu
void LamTronPhepChia(string &x, string &y)
{
	int vt_dau_phay_1 = 0;
	int vt_dau_phay_2 = 0;
	int co_so_10;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == ',')
		{
			vt_dau_phay_1 = i;
			x.erase(x.begin() + i);
			break;
		}
	}
	for (int i = 0; i < y.length(); i++)
	{
		if (y[i] == ',')
		{
			vt_dau_phay_2 = i;
			y.erase(y.begin() + i);
			break;
		}
	}
	// neu x nho hon y
	if (x.length() - vt_dau_phay_1 > y.length() - vt_dau_phay_2 && (vt_dau_phay_1!=0 || vt_dau_phay_2 != 0))
	{
		co_so_10 = x.length() - vt_dau_phay_1 - 1 - (y.length() - vt_dau_phay_2 - 1);
		for (int i = 0; i < co_so_10; i++)
		{
			y.push_back('0');
		}
	}
	//neu y nho hon x
	else if (x.length() - vt_dau_phay_1 < y.length() - vt_dau_phay_2 && (vt_dau_phay_1 != 0 || vt_dau_phay_2 != 0))
	{
		co_so_10 = y.length()  - vt_dau_phay_2 - 1 - (x.length() - vt_dau_phay_1 - 1);
		for (int i = 0; i < co_so_10; i++)
		{
			x.push_back('0');
		}
	}
}
// x la so bi chia , y la so chia (so bi chia lon hon so chia)
// ch? chia ???c tr??ng h?p s? chia n?m trong ki?u int còn s? b? chia thì vô cùng
void Phep_CHia(string x, string y)
{
	LamTronPhepChia(x, y);
	int so_bi_chia = 0;
	int so_chia = Chuyen_Chuoi_Thanh_So_Nguyen(y);
	string kq = "";
	int i = 0;
	int n = x.length();
	int crep = 0;
	int count = 0; // kiem tra co bao nhieu so sau dau cham
	while(i <= n)
	{
		if (i == n)
		{
			if (so_bi_chia % so_chia == 0)
				break;
			else
			{
				if (crep == 0)
				{
					n++;
					kq.push_back(',');
					crep = 1;
					x.push_back('0');
					count++;
				}
				else
				{
					if (Do_Dai_Chuoi_So(x, y) < 0)
					{
						kq.push_back('0');
					}
					n++;
					x.push_back('0');
					count++;
				}
			}
		}
		cout << count << "    ";
		if (count >= 8)
		{
			break;
		}
		if (x[i] == ',')
		{
			so_bi_chia = so_bi_chia * 10;
		}
		else
		{
			so_bi_chia = so_bi_chia * 10 + (x[i] - 48);
		}
		if (so_bi_chia < so_chia && (i >= DemSo(so_chia) && i < n))
		{
			kq.push_back('0');
		}
		int thuong = so_bi_chia / so_chia;
		if (thuong > 0)
		{
			kq.push_back(thuong + 48);
			so_bi_chia = so_bi_chia % so_chia;
		}
		i++;
	}
	// phát hi?n ??u chu?i là d?u ch?m t?c là s? b? chia nh? h?n s? chia nên ta s? thêm s? 0 vào ??u
	if (kq.at(0) == ',')
	{
		kq.insert(kq.begin() + 0, '0');
	}
	cout << kq;
}
void Nhan_2_So_Cung_Dau(string x, string y)
{
	// bat dieu kien neu mot trong 2 bang 0 thi  tra ve ket qua la 0 luon
	if (x[0] == '0' || y[0] == '0')
	{
		string kq = "0";
	}
	int so;
	int so_luu;
	int nho = 0;
	string kq;
	int dem = 0; // la bien luu giu gia tri j theo moc tu 0 < y.length()
	for (int j = y.length() - 1; j >= 0; j--)
	{

		if (j == y.length() - 1)
		{
			int i;
			for (i = x.length() - 1; i >= 0; i--)
			{
				so = (x[i] - 48) * (y[j] - 48) + nho;
				so_luu = so % 10;
				kq.insert(kq.begin() + 0, so_luu + 48);
				nho = so / 10;
			}
			if (i < 0 && nho != 0)
			{
				kq.insert(kq.begin() + 0, nho + 48);
			}
		}
		else
		{
			dem++;
			string kq_phu = "";
			for (int k = 0; k < dem; k++)
			{
				kq_phu.insert(kq_phu.begin() + 0, '0');
			}
			int i;
			for (i = x.length() - 1; i >= 0; i--)
			{
				so = (x[i] - 48) * (y[j] - 48) + nho;
				so_luu = so % 10;
				kq_phu.insert(kq_phu.begin() + 0, so_luu + 48);
				nho = so / 10;
			}
			if (i < 0 && nho != 0)
			{
				kq_phu.insert(kq_phu.begin() + 0, nho + 48);
			}
			kq = Cong_2_SO_Nguyen_Cung_Duong(kq, kq_phu);
		}
	}
	cout << kq;
}

int main()
{
	string x;
	string y;
	string pheptinh;
	cout << "Nhap x: ";
	getline(cin, x);
	cout << "Nhap y: ";
	getline(cin, y);
	///*cout << "nhap phep tinh: ";
	//getline(cin, pheptinh);*/
	/*string kq = Cong(x, y, pheptinh);
	cout << kq;*/
	//string kq = Cong_2_SO_Nguyen_Cung_Duong(x, y);
	//cout << kq;
	/*string kq = Cong_2_SO_Nguyen_Cung_Am(x, y);
	cout << kq;*/
	/*string kq = Cong_2_So_Nguyen_Trai_Dau(x, y);
	cout << kq;*/
	//Phep_CHia(x, y);
	Nhan_2_So_Cung_Dau(x, y);
	system("pause");
	return 0;
}