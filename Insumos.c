#Projeto de distribuição de insumos para estados do Brasil e para o ministério da saúde feitos com struct em C. 

#include <iostream>
#include<stdio.h>
#include<string>	
#include<stdlib.h>
#include<math.h>

using namespace std;

typedef struct {

	string NomeDaVacina;
	double valorU;
	int Quantidade;
	string MesDeVencimento;
	string AnoDeVencimento;
	string NomeDoFabricante;
	string Tecnologia;
	int DosesNecessarias;
	int DistanciaEntreDoses;

}t_vacinas;

typedef struct {

	string NomeDoMedicamento;
	double valorU;
	int Quantidade;
	string MesDeVencimento;
	string AnoDeVencimento;
	string NomeDoFabricante;
	string Dosagem;
	string FormaDeAdm;
	string FormaDeDisp;

}t_medicamentos;

typedef struct {

	string NomeDoEPI;
	double valorU;
	int Quantidade;
	string MesDeVencimento;
	string AnoDeVencimento;
	string NomeDoFabricante;
	string Tipo;
	string InformacaoTipo;
	string Material;
	int QuantidadeLote;

}t_epis;

typedef struct{

	t_vacinas EstadoVacinas[100];
	int QuantidadeArmazenada[100];
	string NomeDaVacinaArmazenada[100];
	string EMesDeVencimento[100];
	string EAnoDeVencimento[100];
	string ENomeDoFabricante[100];
	string ETecnologia[100];
	int EDosesNecessarias[100];
	int EDistanciaEntreDoses[100];
	double EvalorU[100];

	int NumDeVacinas;

}t_estadoVacina;

typedef struct {

	t_medicamentos EstadoMedicamentos[100];
	int QuantidadeArmazenada[100];
	string NomeDoMedicamentoArmazenado[100];
	string EMesDeVencimento[100];
	string EAnoDeVencimento[100];
	string ENomeDoFabricante[100];
	string EDosagem[100];
	string EFormaDeAdm[100];
	string EFormaDeDisp[100];
	double EvalorU[100];

	int NumDeMedicamentos;

}t_estadoMedicamento;

typedef struct {

	t_epis EstadoEpis[100];
	int QuantidadeArmazenada[100];
	string NomeDoEpiArmazenado[100];



	int EQuantidade[100];
	int EQuantidadeLote[100];
	string EMesDeVencimento[100];
	string EAnoDeVencimento[100];
	string ENomeDoFabricante[100];
	string EMaterial[100];
	string ETipo[100];
	string EInformcaoTipo[100];
	double EvalorU[100];

	int NumDeEpis;

}t_estadoEpi;


t_vacinas Vacinas[100];
t_medicamentos Medicamentos[100];
t_epis Epis[100];
t_estadoVacina EVacina[27];
t_estadoMedicamento EMedicamento[27];
t_estadoEpi EEpi[27];


void CadastraVacina(t_vacinas* vacina) {
	int x;

	cout << "Voce quer cadastrar uma vacina certo?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl;
	cin >> x;

	if (x == 1)
	{
		getchar();
		cout << "Digite o nome da Vacina\n";
		getline(cin, vacina->NomeDaVacina);
		cout << "Digite o valor de cada unidade da vacina em reais\n";
		cin >> vacina->valorU;
		getchar();
		cout << "Digite a quantidade de unidades da vacina\n";
		cin >> vacina->Quantidade;
		getchar();
		cout << "Digite o mes de validade da vacina\n";
		getline(cin, vacina->MesDeVencimento);
		cout << "Digite o ano de validade da vacina\n";
		getline(cin, vacina->AnoDeVencimento);
		cout << "Digite o nome do fabricante\n";
		getline(cin, vacina->NomeDoFabricante);
		cout << "Digite a tecnologia ultilizada na vacina\n";
		getline(cin, vacina->Tecnologia);
		cout << "Digite a quantidade de doses necessarias da vacina\n";
		cin >> vacina->DosesNecessarias;
		cout << "Digite a distancia necessaria entre as doses da vacina em dias\n";
		cin >> vacina->DistanciaEntreDoses;

		cout << "Vacina cadastrada com sucesso\n";
	}




}


void VisualizaVacinas(t_vacinas* vacina) {

	int x;

	cout << "Voce quer visualizar o nome das vacinas certo?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
	cin >> x;

	if (x == 1) {

		if (vacina->Quantidade > 0)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Este eh o nome da vacina: " << vacina->NomeDaVacina << endl;
			cout << "Este eh o valor unitario dela em reais: " << vacina->valorU << endl;
			cout << "Este eh a quantidade que o estoque da MS possui: " << vacina->Quantidade << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;

		}
		else
		{
			cout << "Vacina " << vacina->NomeDaVacina << " Fora de estoque" << endl << endl;
		}


	}


}

void DescricaoVacina(t_vacinas* vacina) {

	int x;

	cout << "Voce quer visualizar a descricao das vacinas certo?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
	cin >> x;

	if (x == 1) {

		if (vacina->Quantidade > 0) {
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Este eh o nome da vacina: " << vacina->NomeDaVacina << endl;
			cout << "Este eh o mes do seu vencimento: " << vacina->MesDeVencimento << endl;
			cout << "Este eh o ano do seu vencimaneto: " << vacina->AnoDeVencimento << endl;
			cout << "Este eh o nome do seu fabricante: " << vacina->NomeDoFabricante << endl;
			cout << "Esta eh a tecnlogia da vacina: " << vacina->Tecnologia << endl;
			cout << "Este eh o numero de doses necessarias da vacina: " << vacina->DosesNecessarias << endl;
			cout << "Esta eh a distancia entre as doses da vacina: " << vacina->DistanciaEntreDoses << endl << endl << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		else
		{
			cout << "Vacina nao cadastrada" << endl;
		}
			
	}


}

void AdicionarNoEstado(t_vacinas* AddNoEstado, int VacinasCriadas, t_estadoVacina* VacinaDoEstado) {

	int x;

	cout << "Voce gostaria de retirar um quantidade dessa vacina?" << endl << "Nome da vacina: " << AddNoEstado->NomeDaVacina << endl;
	cout << "Quantidade da vacina: " << AddNoEstado->Quantidade << endl;
	cout << "Digite '1' para SIM e '0' para NAO" << endl;
	cin >> x;

	if (x == 1) {

		cout << "Digite a quantidade de vacinas que voce gostaria de enviar para esse Estado" << endl;
		int Q;
		cin >> Q;

		cout << AddNoEstado->Quantidade << endl;

		if (Q > AddNoEstado->Quantidade)
		{
			cout << "Quantidade maior que o Permetido" << endl;
		}
		else
		{
			for (int i = 0; i < 100; i++) {
				if (i != VacinaDoEstado->NumDeVacinas)
				{
				
				}
				else {
					VacinaDoEstado->NomeDaVacinaArmazenada[i] = AddNoEstado->NomeDaVacina;
					VacinaDoEstado->QuantidadeArmazenada[i] = Q;
					AddNoEstado->Quantidade -= Q;
					VacinaDoEstado->NumDeVacinas++;
					VacinaDoEstado->EvalorU[i] = AddNoEstado->valorU;
					VacinaDoEstado->EMesDeVencimento[i] = AddNoEstado->MesDeVencimento;
					VacinaDoEstado->EAnoDeVencimento[i] = AddNoEstado->AnoDeVencimento;
					VacinaDoEstado->ENomeDoFabricante[i] = AddNoEstado->NomeDoFabricante;
					VacinaDoEstado->EDosesNecessarias[i] = AddNoEstado->DosesNecessarias;
					VacinaDoEstado->EDistanciaEntreDoses[i] = AddNoEstado->DistanciaEntreDoses;
					VacinaDoEstado->ETecnologia[i] = AddNoEstado->Tecnologia;

					cout << "Vacina Enviada para o Estado com sucesso com sucesso" << endl;
					break;

				}
				

			 }
		}




	}

}

void RetornaNomeDasVacinasNosEstados(t_estadoVacina* VacinasNoEstado, int estado) {

	string Nestado[27];
	if (estado == 0)
	{
		Nestado[0] == "Acre";
		cout << "Essas sao as vacinas entegues a este estado: ACRE " << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{
		Nestado[1] == "Alagoas";
		cout << "Essas sao as vacinas entegues a este estado: ALAGOAS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{
		Nestado[2] == "Amazonas";
		cout << "Essas sao as vacinas entegues a este estado: AMAZONAS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{
		Nestado[3] == "Bahia";
		cout << "Essas sao as vacinas entegues a este estado: BAHIA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{
		Nestado[4] == "Ceara";
		cout << "Essas sao as vacinas entegues a este estado: CEARA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 5)
	{
		Nestado[5] == "Destrito Federal";
		cout << "Essas sao as vacinas entegues a este estado: DESTRITO FEDERAL " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 6)
	{
		Nestado[6] == "Espirito Santo";
		cout << "Essas sao as vacinas entegues a este estado: ESPIRITO SANTO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 7)
	{
		Nestado[7] == "Goias";
		cout << "Essas sao as vacinas entegues a este estado: GOIAS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 8)
	{
		Nestado[8] == "Maranhao";
		cout << "Essas sao as vacinas entegues a este estado: MARANHAO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 9)
	{
		Nestado[9] == "Mato Grosso";
		cout << "Essas sao as vacinas entegues a este estado: MATO GROSSO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 10)
	{
		Nestado[10] == "Mato Grosso do Sul";
		cout << "Essas sao as vacinas entegues a este estado: MATO GROSSO DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 11)
	{
		Nestado[11] == "Minas Gerais";
		cout << "Essas sao as vacinas entegues a este estado: MINAS GERAIS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 12)
	{
		Nestado[12] == "Para";
		cout << "Essas sao as vacinas entegues a este estado: PARA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 13)
	{
		Nestado[13] == "Paraiba";
		cout << "Essas sao as vacinas entegues a este estado: PARAIBA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 14)
	{
		Nestado[14] == "Parana";
		cout << "Essas sao as vacinas entegues a este estado: PARANA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 15)
	{
		Nestado[15] == "Pernambuco";
		cout << "Essas sao as vacinas entegues a este estado: PERNAMBUCO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 16)
	{
		Nestado[16] == "Piaui";
		cout << "Essas sao as vacinas entegues a este estado: PIAUI " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 17)
	{
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO DE JANEIRO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 18)
	{
		Nestado[18] == "Rio Grande do Norte";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO GRANDE DO NORTE " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 19)
	{
		Nestado[19] == "Rio Grande do Sul";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO GRANDE DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 20)
	{
		Nestado[20] == "Rondonia";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RONDONIA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 21)
	{
		Nestado[21] == "Roraima";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RORAIMA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{
		Nestado[22] == "Santa Catarina";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SANTA CATARINA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{
		Nestado[23] == "Sao Paulo";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SAO PAULO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{
		Nestado[24] == "Serjipe";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SERJIPE " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{
		Nestado[25] == "Tocantins";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: TOCANTINS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{
		Nestado[26] == "Amapa";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: AMAPA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada:" << VacinasNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}

	

}
void RetornaDescricaoDaVacina(t_estadoVacina* VacinasNoEstado, int estado) {

	string Nestado[27];
	if (estado == 0)
	{
		Nestado[0] == "Acre";
		cout << "Essas sao as descricoes das vacinas entregue ao estado do: ACRE " << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{
		Nestado[1] == "Alagoas";
		cout << "Essas sao as vacinas entegues a este estado: ALAGOAS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{
		Nestado[2] == "Amazonas";
		cout << "Essas sao as vacinas entegues a este estado: AMAZONAS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{
		Nestado[3] == "Bahia";
		cout << "Essas sao as vacinas entegues a este estado: BAHIA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{
		Nestado[4] == "Ceara";
		cout << "Essas sao as vacinas entegues a este estado: CEARA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 5)
	{
		Nestado[5] == "Destrito Federal";
		cout << "Essas sao as vacinas entegues a este estado: DESTRITO FEDERAL " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 6)
	{
		Nestado[6] == "Espirito Santo";
		cout << "Essas sao as vacinas entegues a este estado: ESPIRITO SANTO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 7)
	{
		Nestado[7] == "Goias";
		cout << "Essas sao as vacinas entegues a este estado: GOIAS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 8)
	{
		Nestado[8] == "Maranhao";
		cout << "Essas sao as vacinas entegues a este estado: MARANHAO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 9)
	{
		Nestado[9] == "Mato Grosso";
		cout << "Essas sao as vacinas entegues a este estado: MATO GROSSO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 10)
	{
		Nestado[10] == "Mato Grosso do Sul";
		cout << "Essas sao as vacinas entegues a este estado: MATO GROSSO DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 11)
	{
		Nestado[11] == "Minas Gerais";
		cout << "Essas sao as vacinas entegues a este estado: MINAS GERAIS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 12)
	{
		Nestado[12] == "Para";
		cout << "Essas sao as vacinas entegues a este estado: PARA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 13)
	{
		Nestado[13] == "Paraiba";
		cout << "Essas sao as vacinas entegues a este estado: PARAIBA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 14)
	{
		Nestado[14] == "Parana";
		cout << "Essas sao as vacinas entegues a este estado: PARANA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 15)
	{
		Nestado[15] == "Pernambuco";
		cout << "Essas sao as vacinas entegues a este estado: PERNAMBUCO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 16)
	{
		Nestado[16] == "Piaui";
		cout << "Essas sao as vacinas entegues a este estado: PIAUI " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 17)
	{
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO DE JANEIRO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 18)
	{
		Nestado[18] == "Rio Grande do Norte";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO GRANDE DO NORTE " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 19)
	{
		Nestado[19] == "Rio Grande do Sul";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO GRANDE DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 20)
	{
		Nestado[20] == "Rondonia";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RONDONIA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 21)
	{
		Nestado[21] == "Roraima";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RORAIMA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{
		Nestado[22] == "Santa Catarina";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SANTA CATARINA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{
		Nestado[23] == "Sao Paulo";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SAO PAULO " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{
		Nestado[24] == "Serjipe";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SERJIPE " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{
		Nestado[25] == "Tocantins";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: TOCANTINS " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{
		Nestado[26] == "Amapa";
		
		cout << "Essas sao as vacinas entegues a este estado: AMAPA " << Nestado[estado] << endl;

		for (int i = 0; i < VacinasNoEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinasNoEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinasNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinasNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinasNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinasNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinasNoEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinasNoEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinasNoEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}

}

void ConsultaVacinaNoEstado(t_estadoVacina *Estado) {

	cout << "Esta sao as vacinas enviadas para este Estado: " <<endl;

	for (int i = 0; i < Estado->NumDeVacinas; i++)
	{
		cout << "Este eh o nome da vacina: " << Estado->NomeDaVacinaArmazenada[i] << endl;
		if (Estado->QuantidadeArmazenada[i] == 0)
		{
			cout << "Estoque dessa vacina neste estado esgotou" << endl;
		}
		else {
			cout << "Este eh o estoque dessa vacina neste Estado: " << Estado->QuantidadeArmazenada[i] << endl;
		}
		cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		cout << "Este eh o valor dessa vacina unitario dessa vacina em reias: " << Estado->EvalorU[i] << endl;
		cout << "Este eh o mes e o ano de validade dessa vacina: " << Estado->EMesDeVencimento[i] << "/" << Estado->EAnoDeVencimento[i] << endl;
		cout << "Esta foi a tecnologia ultilizada na vacina: " << Estado->ETecnologia[i] << endl;
		cout << "Esta eh a empresa que a criou: " << Estado->ENomeDoFabricante[i] << endl;
		cout << "Este eh o numero de doses necessarias e a quantidade de dias necessarios para se tomar entre as doses: " << Estado->EDosesNecessarias[i] << "/////" << Estado->EDistanciaEntreDoses[i] << endl << endl << endl << endl << endl;
		cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	}


}

void CadastraMedicamento(t_medicamentos* medicamento) {
	int x;

	cout << "Voce quer cadastrar um medicamento?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl;
	cin >> x;

	if (x == 1)
	{
		getchar();
		cout << "Digite o nome do Medicamento\n";
		getline(cin, medicamento->NomeDoMedicamento);
		cout << "Digite o valor de cada unidade do medicamento em reais\n";
		cin >> medicamento->valorU;
		getchar();
		cout << "Digite a quantidade de unidades do medicamento\n";
		cin >> medicamento->Quantidade;
		getchar();
		cout << "Digite o mes de validade do medicamento\n";
		getline(cin, medicamento->MesDeVencimento);
		cout << "Digite o ano de validade do medicamento\n";
		getline(cin, medicamento->AnoDeVencimento);
		cout << "Digite o nome do fabricante\n";
		getline(cin, medicamento->NomeDoFabricante);
		cout << "Digite a dosagem ultilizada no medicamento\n";
		getline(cin, medicamento->Dosagem);
		cout << "Digite a forma de administracao do medicamento\n";
		cin >> medicamento->FormaDeAdm;
		cout << "Digite a forma de disponibilização do medicamento\n";
		cin >> medicamento->FormaDeDisp;

		cout << "Medicamento cadastrado com sucesso\n";
	}
}

void VisualizaMedicamentos(t_medicamentos* medicamento) {

	int x;

	cout << "Voce quer visualizar o nome dos medicamentos?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
	cin >> x;

	if (x == 1) {

		if (medicamento->Quantidade > 0)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Este eh o nome do medicamento: " << medicamento->NomeDoMedicamento << endl;
			cout << "Este eh o valor unitario do medicamento: " << medicamento->valorU << endl;
			cout << "Esta eh a quantidade que o estoque do MS possui: " << medicamento->Quantidade << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		else
		{
			cout << "Medicamento " << medicamento->NomeDoMedicamento << " Fora de estoque" << endl << endl;
		}
	}
}

void DescricaoMedicamento(t_medicamentos* medicamento) {

	int x;

	cout << "Voce quer visualizar a descricao das medicamentos certo?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
	cin >> x;

	if (x == 1) {
		if (medicamento->Quantidade) {
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Este eh o nome do medicamento: " << medicamento->NomeDoMedicamento << endl;
			cout << "Este eh o mes do seu vencimento: " << medicamento->MesDeVencimento << endl;
			cout << "Este eh o ano do seu vencimaneto: " << medicamento->AnoDeVencimento << endl;
			cout << "Este eh o nome do seu fabricante: " << medicamento->NomeDoFabricante << endl;
			cout << "Esta eh a tecnlogia do medicamento: " << medicamento->Dosagem << endl;
			cout << "Esta é a forma de administracao do medicamento: " << medicamento->FormaDeAdm << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << medicamento->FormaDeDisp << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		else
		{
			cout << "Medicamento nao cadastrado" << endl;
		}
	}
}

void AdicionarMedicamentoNoEstado(t_medicamentos* AddNoEstado, int MedicamentosCriados, t_estadoMedicamento* MedicamentoDoEstado) {

	int x;

	cout << "Voce gostaria de retirar um quantidade dessa medicamento?" << endl << "Nome do medicamento: " << AddNoEstado->NomeDoMedicamento << endl;
	cout << "Quantidade do medicamento: " << AddNoEstado->Quantidade << endl;
	cout << "Digite '1' para SIM e '0' para NAO" << endl;
	cin >> x;

	if (x == 1) {

		cout << "Digite a quantidade de medicamentos que voce gostaria de enviar para esse Estado" << endl;
		int Q;
		cin >> Q;

		cout << AddNoEstado->Quantidade << endl;

		if (Q > AddNoEstado->Quantidade)
		{
			cout << "Quantidade maior que o Permetido" << endl;
		}
		else
		{
			for (int i = 0; i < 100; i++) {
				if (i != MedicamentoDoEstado->NumDeMedicamentos)
				{

				}
				else {
					MedicamentoDoEstado->NomeDoMedicamentoArmazenado[i] = AddNoEstado->NomeDoMedicamento;
					MedicamentoDoEstado->QuantidadeArmazenada[i] = Q;
					AddNoEstado->Quantidade -= Q;
					MedicamentoDoEstado->NumDeMedicamentos++;
					cout << "Medicamento Enviada para o Estado com sucesso com sucesso" << endl;
					break;
				}
			}
		}
	}
}

void ConsultaMedicamentoNoEstado(t_estadoMedicamento* Estado) {

	cout << "Este sao os medicamentos enviados para este Estado: " << endl;

	for (int i = 0; i < Estado->NumDeMedicamentos; i++)
	{
		cout << "Este eh o nome do medicamento: " << Estado->NomeDoMedicamentoArmazenado[i] << endl;
		if (Estado->QuantidadeArmazenada[i] == 0)
		{
			cout << "Estoque desse medicamento neste estado esgotou" << endl;
		}
		else {
			cout << "Este eh o estoque desse medicamento neste Estado: " << Estado->QuantidadeArmazenada[i] << endl;
		}

		cout << "Este eh o valor unitario desse medicamento em reais eh: " << Estado->EvalorU[i] << endl;
		cout << "Este eh o mes e o ano de validade desse medicamento: " << Estado->EMesDeVencimento[i] << "/" << Estado->EAnoDeVencimento[i] << endl;
		cout << "Esta eh a dosagem necessaria do medicamento: " << Estado->EDosagem[i] << endl;
		cout << "Esta eh a empresa que a criou: " << Estado->ENomeDoFabricante[i] << endl;
		cout << "Esta eh a forma de administracao do medicamento: " << Estado->EFormaDeAdm[i] << endl << endl << endl << endl << endl;
	}


}

void RetornaNomeDosMedicamentosNosEstados(t_estadoMedicamento* MedicamentosNoEstado, int estado) {

	string Nestado[27];
	if (estado == 0)
	{
		Nestado[0] == "Acre";
		cout << "Essas sao os medicamentos entregues a este estado: ACRE " << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 1)
	{
		Nestado[1] == "Alagoas";
		cout << "Essas sao os medicamentos entregues a este estado: ALAGOAS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 2)
	{
		Nestado[2] == "Amazonas";
		cout << "Essas sao os medicamentos entregues a este estado: AMAZONAS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 3)
	{
		Nestado[3] == "Bahia";
		cout << "Essas sao os medicamentos entregues a este estado: BAHIA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 4)
	{
		Nestado[4] == "Ceara";
		cout << "Essas sao os medicamentos entregues a este estado: CEARA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 5)
	{
		Nestado[5] == "Destrito Federal";
		cout << "Essas sao os medicamentos entregues a este estado: DESTRITO FEDERAL " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 6)
	{
		Nestado[6] == "Espirito Santo";
		cout << "Essas sao os medicamentos entregues a este estado: ESPIRITO SANTO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 7)
	{
		Nestado[7] == "Goias";
		cout << "Essas sao os medicamentos entregues a este estado: GOIAS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 8)
	{
		Nestado[8] == "Maranhao";
		cout << "Essas sao os medicamentos entregues a este estado: MARANHAO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 9)
	{
		Nestado[9] == "Mato Grosso";
		cout << "Essas sao os medicamentos entregues a este estado: MATO GROSSO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 10)
	{
		Nestado[10] == "Mato Grosso do Sul";
		cout << "Essas sao os medicamentos entregues a este estado: MATO GROSSO DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 11)
	{
		Nestado[11] == "Minas Gerais";
		cout << "Essas sao os medicamentos entregues a este estado: MINAS GERAIS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 12)
	{
		Nestado[12] == "Para";
		cout << "Essas sao os medicamentos entregues a este estado: PARA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 13)
	{
		Nestado[13] == "Paraiba";
		cout << "Essas sao os medicamentos entregues a este estado: PARAIBA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 14)
	{
		Nestado[14] == "Parana";
		cout << "Essas sao os medicamentos entregues a este estado: PARANA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 15)
	{
		Nestado[15] == "Pernambuco";
		cout << "Essas sao os medicamentos entregues a este estado: PERNAMBUCO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 16)
	{
		Nestado[16] == "Piaui";
		cout << "Essas sao os medicamentos entregues a este estado: PIAUI " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 17)
	{
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: RIO DE JANEIRO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 18)
	{
		Nestado[18] == "Rio Grande do Norte";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: RIO GRANDE DO NORTE " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 19)
	{
		Nestado[19] == "Rio Grande do Sul";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: RIO GRANDE DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 20)
	{
		Nestado[20] == "Rondonia";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: RONDONIA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	else if (estado == 21)
	{
		Nestado[21] == "Roraima";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: RORAIMA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 22)
	{
		Nestado[22] == "Santa Catarina";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: SANTA CATARINA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 23)
	{
		Nestado[23] == "Sao Paulo";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: SAO PAULO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 24)
	{
		Nestado[24] == "Serjipe";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: SERJIPE " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 25)
	{
		Nestado[25] == "Tocantins";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: TOCANTINS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}
	if (estado == 26)
	{
		Nestado[26] == "Amapa";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao os medicamentos entregues a este estado: AMAPA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "Nome do Medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do Medicamento armazenado:" << MedicamentosNoEstado->QuantidadeArmazenada[i] << endl;
		}
	}



}


void RetornaDescricaoDoMedicamento(t_estadoMedicamento* MedicamentosNoEstado, int estado) {

	string Nestado[27];
	if (estado == 0)
	{
		Nestado[0] == "Acre";
		cout << "Esses sao as descricoes dos medicamentos entregues ao estado do: ACRE " << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{
		Nestado[1] == "Alagoas";
		cout << "Esses sao os medicamentos entregues ao este estado: ALAGOAS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{
		Nestado[2] == "Amazonas";
		cout << "Esses sao os medicamentos entregues ao este estado: AMAZONAS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{
		Nestado[3] == "Bahia";
		cout << "Esses sao os medicamentos entregues ao este estado: BAHIA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{
		Nestado[4] == "Ceara";
		cout << "Esses sao os medicamentos entregues ao este estado: CEARA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 5)
	{
		Nestado[5] == "Destrito Federal";
		cout << "Esses sao os medicamentos entregues ao este estado: DESTRITO FEDERAL " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 6)
	{
		Nestado[6] == "Espirito Santo";
		cout << "Esses sao os medicamentos entregues ao este estado: ESPIRITO SANTO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 7)
	{
		Nestado[7] == "Goias";
		cout << "Esses sao os medicamentos entregues ao este estado: GOIAS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 8)
	{
		Nestado[8] == "Maranhao";
		cout << "Esses sao os medicamentos entregues ao este estado: MARANHAO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 9)
	{
		Nestado[9] == "Mato Grosso";
		cout << "Esses sao os medicamentos entregues ao este estado: MATO GROSSO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 10)
	{
		Nestado[10] == "Mato Grosso do Sul";
		cout << "Esses sao os medicamentos entregues ao este estado: MATO GROSSO DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 11)
	{
		Nestado[11] == "Minas Gerais";
		cout << "Esses sao os medicamentos entregues ao este estado: MINAS GERAIS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 12)
	{
		Nestado[12] == "Para";
		cout << "Esses sao os medicamentos entregues ao este estado: PARA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 13)
	{
		Nestado[13] == "Paraiba";
		cout << "Esses sao os medicamentos entregues ao este estado: PARAIBA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 14)
	{
		Nestado[14] == "Parana";
		cout << "Esses sao os medicamentos entregues ao este estado: PARANA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 15)
	{
		Nestado[15] == "Pernambuco";
		cout << "Esses sao os medicamentos entregues ao este estado: PERNAMBUCO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 16)
	{
		Nestado[16] == "Piaui";
		cout << "Esses sao os medicamentos entregues ao este estado: PIAUI " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 17)
	{
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: RIO DE JANEIRO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 18)
	{
		Nestado[18] == "Rio Grande do Norte";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: RIO GRANDE DO NORTE " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 19)
	{
		Nestado[19] == "Rio Grande do Sul";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: RIO GRANDE DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 20)
	{
		Nestado[20] == "Rondonia";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: RONDONIA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 21)
	{
		Nestado[21] == "Roraima";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: RORAIMA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{
		Nestado[22] == "Santa Catarina";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: SANTA CATARINA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{
		Nestado[23] == "Sao Paulo";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: SAO PAULO " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{
		Nestado[24] == "Serjipe";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: SERJIPE " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{
		Nestado[25] == "Tocantins";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os medicamentos entregues ao este estado: TOCANTINS " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{
		Nestado[26] == "Amapa";

		cout << "Esses sao os medicamentos entregues ao este estado: AMAPA " << Nestado[estado] << endl;

		for (int i = 0; i < MedicamentosNoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentosNoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentosNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentosNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do medicamento: " << MedicamentosNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentosNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem necessaria do medicamento: " << MedicamentosNoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administração do medicamento: " << MedicamentosNoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de disponibilização do medicamento: " << MedicamentosNoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
}


void ConsultaTodosOsInsumosNosEstados(t_estadoVacina *VacinaEstado,t_estadoEpi *EpiEstado,t_estadoMedicamento *MedicamentoEstado ,int estado) {

	if (estado == 0)
	{
		
		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: ACRE " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: ALAGOAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: AMAZONAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: BAHIA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: CEARA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 5)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: DESTRITO FEDERAL " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 6)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: ESPIRITO SANTO " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 7)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: GOIAS " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 8)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MARANHAO " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 9)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MATO GROSS " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 10)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MATO GROSSO DO SUL " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 11)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MINAS GERAIS " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 12)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PARA " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 13)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PARAIBA " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 14)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PARANA " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 15)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PERNAMBUCO " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 16)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PIAUI " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 17)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RIO DE JANEIRO " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 18)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RIO GRANDE DO NORTE " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 19)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RIO GRANDE DO SUL " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 20)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RONDONIA " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 21)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RORAIMA " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: SANTA CATARINA " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: SAO PAULO " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: SERJIPE " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: TOCANTINS " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: AMAPA " << endl;


		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
}

void ConsultaTodosOsInsumosPorEstados(t_estadoVacina* VacinaEstado, t_estadoEpi* EpiEstado, t_estadoMedicamento* MedicamentoEstado, int estado) {
	if (estado == 0)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""ACRE " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""ALAGOAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""AMAZONAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""BAHIA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""CEARA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 5)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""DESTRITO FEDERAL " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 6)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: ""ESPIRITO SANTO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 7)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""GOIAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 8)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""MARANHAO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 9)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""MATO GROSSO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 10)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""MATO GROSSO DO SUL " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 11)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""MINAS GERAIS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 12)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""PARA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 13)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""PARAIBA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 14)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""PARANA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 15)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""PERNAMBUCO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << 
			endl; cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl; cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 16)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""PIAUI " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 17)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""RIO DE JANEIRO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 18)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""RIO GRANDE DO NORTE " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 19)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""RIO GRANDE DO SUL " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 20)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""RONDONIA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 21)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""RORAIMA" << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""SANTA CATARINA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""SAO PAULO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""SERJIPE " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""TOCANTINS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do:""AMAPA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Quantidade da vacina armazenada: " << VacinaEstado->QuantidadeArmazenada[i] << endl;		
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;

		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Quantidade do medicamento armazenado: " << MedicamentoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;

		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da Epi: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do Epi armazenado: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;

		}
	}


}






void ConsultaAdescricaoTodosOsInsumosNosEstados(t_estadoVacina* VacinaEstado, t_estadoEpi* EpiEstado, t_estadoMedicamento* MedicamentoEstado, int estado) {

	if (estado == 0)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: ACRE " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: ALAGOAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: AMAZONAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: BAHIA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: CEARA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 5)
	{

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 6)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: ESPIRITO SANTO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 7)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: GOIAS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 8)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MARANHAO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 9)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MATO GROSS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 10)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MATO GROSSO DO SUL " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 11)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: MINAS GERAIS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 12)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PARA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 13)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PARAIBA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 14)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PARANA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 15)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PERNAMBUCO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 16)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: PIAUI " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 17)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RIO DE JANEIRO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 18)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RIO GRANDE DO NORTE " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 19)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RIO GRANDE DO SUL " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 20)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RONDONIA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 21)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: RORAIMA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: SANTA CATARINA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: SAO PAULO " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: SERJIPE " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: TOCANTINS " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{

		cout << "Essas sao as descricoes das vacinas, medicamentos e EPIs entreguem ao estado do: AMAPA " << endl;

		for (int i = 0; i < VacinaEstado->NumDeVacinas; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da vacina: " << VacinaEstado->NomeDaVacinaArmazenada[i] << endl;
			cout << "Valor da vacina: " << VacinaEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da vacina: " << VacinaEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da vacina: " << VacinaEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << VacinaEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta foi a tecnologia ultilizada na vacina: " << VacinaEstado->ETecnologia[i] << endl;
			cout << "Esta sao as doses necessarias da vacina: " << VacinaEstado->EDosesNecessarias[i] << endl;
			cout << "Esta eh a distancia necessaria entre as doses da vacina: " << VacinaEstado->EDistanciaEntreDoses[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < MedicamentoEstado->NumDeMedicamentos; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do medicamento: " << MedicamentoEstado->NomeDoMedicamentoArmazenado[i] << endl;
			cout << "Valor do medicamento: " << MedicamentoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do medicamento: " << MedicamentoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da medicamento: " << MedicamentoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << MedicamentoEstado->ENomeDoFabricante[i] << endl;
			cout << "Esta eh a dosagem do medicamento: " << MedicamentoEstado->EDosagem[i] << endl;
			cout << "Esta eh a forma de administracao do medicamento: " << MedicamentoEstado->EFormaDeAdm[i] << endl;
			cout << "Esta eh a forma de dispersao do medicamento: " << MedicamentoEstado->EFormaDeDisp[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
		for (int i = 0; i < EpiEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome da EPI: " << EpiEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor da EPI: " << EpiEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento da EPI: " << EpiEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpiEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpiEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o tipo dessa Epi: " << EpiEstado->ETipo[i] << endl;
			cout << "Esta sao as informacoes do tipo desta Epi: " << EpiEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}


}

void CadastraEpi(t_epis* epi) {
	int a;

	cout << "Gostaria de cadastrar um novo EPI (Equipamento de Protecao Individual)?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl;
	cin >> a;

	if (a == 1)
	{
		getchar();
		cout << "Digite o nome do insumo de seu EPI\n";
		getline(cin, epi->NomeDoEPI);
		cout << "Digite o valor do insumo por item de seu EPI em reais\n";
		cin >> epi->valorU;
		cout << "Digite o numero itens que estao disponiveis\n ";
		cin >> epi->Quantidade;
		cout << "Digite o numero de unidades por item do seu insumo\n";
		cin >> epi->QuantidadeLote;
		getchar();
		cout << "Digite o mes de validade do insumo de seu EPI\n";
		getline(cin, epi->MesDeVencimento);
		cout << "Digite o ano de validade do insumo de seu EPI\n";
		getline(cin, epi->AnoDeVencimento);
		cout << "Digite o nome do fabricante\n";
		getline(cin, epi->NomeDoFabricante);
		cout << "Informe o tipo de material do insumo do Epi  \n";
		getline(cin, epi->Material);
		cout << "Digite o tipo ou classificacao do modelo do insumo de seu Epi.\n - Caso nao seja necessario, digite 'Padrao'  \n";
		getline(cin, epi->Tipo);

		if (epi->Tipo != "padrao" || epi->Tipo != "Padrao") {
			cout << "Informe a descricao do tipo do Epi Classificado d\n";
			getline(cin, epi->InformacaoTipo);
		}


		cout << "Insumo cadastrado com sucesso\n";
	}
}


///////////////////////


void DescricaoEpi(t_epis* epi) {

	int b;

	cout << "Gostaria de visualizar a descricao dos itens do EPI?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
	cin >> b;

	if (b == 1) {
		if (epi->Quantidade) {
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Este eh o nome do Epi: " << epi->NomeDoEPI << endl;
			cout << "Esta eh a quatidade de unidades por item: " << epi->QuantidadeLote << "unidades por item" << endl;
			cout << "Este eh o mes do seu vencimento: " << epi->MesDeVencimento << endl;
			cout << "Este eh o mes do seu vencimento: " << epi->MesDeVencimento << endl;
			cout << "Este eh o ano do seu vencimaneto: " << epi->AnoDeVencimento << endl;
			cout << "Este eh o nome do seu fabricante: " << epi->NomeDoFabricante << endl;

			cout << "Esta eh a composicao de seu material: " << epi->Material << endl;
			cout << "Este eh o seu tipo: " << epi->Tipo << endl;
			if (epi->Tipo != "padrao" || epi->Tipo != "Padrao")
				cout << "Esta eh a descricao do produto: " << epi->InformacaoTipo << endl << endl << endl;
		}
		else
		{
			cout << "Epi nao cadastrada" << endl;
		}
		cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	}


}

/////////////////////////////////////////



void VisualizaEpis(t_epis* epi) {

	int a;

	cout << "Gostaria de visualizar o nome de todos os EPIs que a MS possui?" << endl;
	cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
	cin >> a;

	if (a == 1) {

		if (epi->Quantidade > 0)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Este eh o Nome do Epi: " << epi->NomeDoEPI << endl;
			cout << "Este eh o valor unitario dela: " << epi->valorU << endl;
			cout << "Este eh a quantidade que o estoque da MS possui: " << epi->Quantidade << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;

		}
		else
		{
			cout << "Vacina " << epi->NomeDoEPI << " Fora de estoque" << endl << endl << endl;
		}


	}


}

///


void AdicionarEpiNoEstado(t_epis* AddNoEstado, int EpisCriadas, t_estadoEpi* EpiDoEstado) {

	int x;

	cout << "Gostaria de retirar uma quantidade desse EPI?" << endl << "Nome do EPI: " << AddNoEstado->NomeDoEPI << endl;
	cout << "Quantidade do EPI: " << AddNoEstado->Quantidade << endl;
	cout << "Digite '1' para SIM e '0' para NAO" << endl;
	cin >> x;

	if (x == 1) {

		cout << "Digite a quantidade de insumos de EPque voce gostaria de enviar para esse Estado" << endl;
		int Q;
		cin >> Q;

		cout << AddNoEstado->Quantidade << endl;

		if (Q > AddNoEstado->Quantidade)
		{
			cout << "Quantidade maior que o Permetido" << endl;
		}
		else
		{
			for (int i = 0; i < 100; i++) {
				if (i != EpiDoEstado->NumDeEpis)
				{

				}
				else {

					EpiDoEstado->NomeDoEpiArmazenado[i] = AddNoEstado->NomeDoEPI;
					EpiDoEstado->QuantidadeArmazenada[i] = Q;
					AddNoEstado->Quantidade -= Q;
					EpiDoEstado->NumDeEpis++;
					EpiDoEstado->EvalorU[i] = AddNoEstado->valorU;
					EpiDoEstado->EMesDeVencimento[i] = AddNoEstado->MesDeVencimento;
					EpiDoEstado->EAnoDeVencimento[i] = AddNoEstado->AnoDeVencimento;
					EpiDoEstado->ENomeDoFabricante[i] = AddNoEstado->NomeDoFabricante;

					EpiDoEstado->ETipo[i] = AddNoEstado->Tipo;
					EpiDoEstado->EInformcaoTipo[i] = AddNoEstado->InformacaoTipo;
					EpiDoEstado->EMaterial[i] = AddNoEstado->Material;


					cout << "EPI Enviada para o Estado com sucesso com sucesso" << endl;
					break;

				}


			}
		}
	}
}

void RetornaDescricaoDoEpi(t_estadoEpi* EpisNoEstado, int estado) {

	string Nestado[27];
	if (estado == 0)
	{
		Nestado[0] == "Acre";
		cout << "Essas sao as descricoes das vacinas entregue ao estado do: ACRE " << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do EPI: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor Do EPI: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do EPI: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento da EPI: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{
		Nestado[1] == "Alagoas";
		cout << "Essas sao as vacinas entegues a este estado: ALAGOAS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{
		Nestado[2] == "Amazonas";
		cout << "Essas sao as vacinas entegues a este estado: AMAZONAS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{
		Nestado[3] == "Bahia";
		cout << "Essas sao as vacinas entegues a este estado: BAHIA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{
		Nestado[4] == "Ceara";
		cout << "Essas sao as vacinas entegues a este estado: CEARA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 5)
	{
		Nestado[5] == "Destrito Federal";
		cout << "Essas sao as vacinas entegues a este estado: DESTRITO FEDERAL " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 6)
	{
		Nestado[6] == "Espirito Santo";
		cout << "Essas sao as vacinas entegues a este estado: ESPIRITO SANTO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 7)
	{
		Nestado[7] == "Goias";
		cout << "Essas sao as vacinas entegues a este estado: GOIAS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 8)
	{
		Nestado[8] == "Maranhao";
		cout << "Essas sao as vacinas entegues a este estado: MARANHAO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 9)
	{
		Nestado[9] == "Mato Grosso";
		cout << "Essas sao as vacinas entegues a este estado: MATO GROSSO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 10)
	{
		Nestado[10] == "Mato Grosso do Sul";
		cout << "Essas sao as vacinas entegues a este estado: MATO GROSSO DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 11)
	{
		Nestado[11] == "Minas Gerais";
		cout << "Essas sao as vacinas entegues a este estado: MINAS GERAIS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 12)
	{
		Nestado[12] == "Para";
		cout << "Essas sao as vacinas entegues a este estado: PARA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 13)
	{
		Nestado[13] == "Paraiba";
		cout << "Essas sao as vacinas entegues a este estado: PARAIBA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 14)
	{
		Nestado[14] == "Parana";
		cout << "Essas sao as vacinas entegues a este estado: PARANA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 15)
	{
		Nestado[15] == "Pernambuco";
		cout << "Essas sao as vacinas entegues a este estado: PERNAMBUCO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 16)
	{
		Nestado[16] == "Piaui";
		cout << "Essas sao as vacinas entegues a este estado: PIAUI " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 17)
	{
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO DE JANEIRO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 18)
	{
		Nestado[18] == "Rio Grande do Norte";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO GRANDE DO NORTE " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 19)
	{
		Nestado[19] == "Rio Grande do Sul";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RIO GRANDE DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 20)
	{
		Nestado[20] == "Rondonia";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RONDONIA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 21)
	{
		Nestado[21] == "Roraima";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: RORAIMA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{
		Nestado[22] == "Santa Catarina";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SANTA CATARINA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{
		Nestado[23] == "Sao Paulo";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SAO PAULO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{
		Nestado[24] == "Serjipe";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: SERJIPE " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{
		Nestado[25] == "Tocantins";
		Nestado[17] == "Rio de Janeiro";
		cout << "Essas sao as vacinas entegues a este estado: TOCANTINS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{
		Nestado[26] == "Amapa";

		cout << "Essas sao as vacinas entegues a este estado: AMAPA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Valor do Epi: " << EpisNoEstado->EvalorU[i] << endl;
			cout << "Mes de vencimento do Epi: " << EpisNoEstado->EMesDeVencimento[i] << endl;
			cout << "Ano de vencimento do Epi: " << EpisNoEstado->EAnoDeVencimento[i] << endl;
			cout << "Este eh o nome do fabricante: " << EpisNoEstado->ENomeDoFabricante[i] << endl;
			cout << "Este eh o material do EPI: " << EpisNoEstado->EMaterial[i] << endl;
			cout << "Este eh o tipo/classificacao do EPI: " << EpisNoEstado->ETipo[i] << endl;
			cout << "Esta eh a descricao do tipo do EPI: " << EpisNoEstado->EInformcaoTipo[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}

}

void ConsultaEpiNoEstado(t_estadoEpi* Estado) {

	cout << "Este  eh o total de EPIs enviados para este Estado: " << endl;

	for (int i = 0; i < Estado->NumDeEpis; i++)
	{
		cout << "Este eh o nome do EPI: " << Estado->NomeDoEpiArmazenado[i] << endl;
		if (Estado->QuantidadeArmazenada[i] == 0)
		{
			cout << "Estoque desse Epi neste estado esgotou" << endl;
		}
		else {
			cout << "Este eh o estoque desse EPI neste Estado: " << Estado->QuantidadeArmazenada[i] << endl;
		}

		cout << "Este eh o valor dessa vacina unitario desse EPI em reias: " << Estado->EvalorU[i] << endl;
		cout << "Este eh o mes e o ano de validade desse EPI: " << Estado->EMesDeVencimento[i] << "/" << Estado->EAnoDeVencimento[i] << endl;
		cout << "Esta eh o seu material de composicao: " << Estado->EMaterial[i] << endl;
		cout << "Esta eh a empresa que o fabricou: " << Estado->ENomeDoFabricante[i] << endl;
		cout << "Esta eh sua classificacao/modelo  : " << Estado->EInformcaoTipo[i] << endl << endl << endl << endl << endl;
	}


}








void RetornaNomeEpiNosEstados(t_estadoEpi* EpisNoEstado, int estado) {

	string Nestado[27];
	if (estado == 0)
	{
		Nestado[0] == "Acre";
		cout << "Esses sao os EPIs entregues a este estado: ACRE " << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 1)
	{
		Nestado[1] == "Alagoas";
		cout << "Esses sao os EPIs entregues a este estado: ALAGOAS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 2)
	{
		Nestado[2] == "Amazonas";
		cout << "Esses sao os EPIs entregues a este estado: AMAZONAS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 3)
	{
		Nestado[3] == "Bahia";
		cout << "Esses sao os EPIs entregues a este estado: BAHIA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 4)
	{
		Nestado[4] == "Ceara";
		cout << "Esses sao os EPIs entregues a este estado: CEARA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 5)
	{
		Nestado[5] == "Destrito Federal";
		cout << "Esses sao os EPIs entregues a este estado: DESTRITO FEDERAL " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 6)
	{
		Nestado[6] == "Espirito Santo";
		cout << "Esses sao os EPIs entregues a este estado: ESPIRITO SANTO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 7)
	{
		Nestado[7] == "Goias";
		cout << "Esses sao os EPIs entregues a este estado: GOIAS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 8)
	{
		Nestado[8] == "Maranhao";
		cout << "Esses sao os EPIs entregues a este estado: MARANHAO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 9)
	{
		Nestado[9] == "Mato Grosso";
		cout << "Esses sao os EPIs entregues a este estado: MATO GROSSO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 10)
	{
		Nestado[10] == "Mato Grosso do Sul";
		cout << "Esses sao os EPIs entregues a este estado: MATO GROSSO DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 11)
	{
		Nestado[11] == "Minas Gerais";
		cout << "Esses sao os EPIs entregues a este estado: MINAS GERAIS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 12)
	{
		Nestado[12] == "Para";
		cout << "Esses sao os EPIs entregues a este estado: PARA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 13)
	{
		Nestado[13] == "Paraiba";
		cout << "Esses sao os EPIs entregues a este estado: PARAIBA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 14)
	{
		Nestado[14] == "Parana";
		cout << "Esses sao os EPIs entregues a este estado: PARANA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 15)
	{
		Nestado[15] == "Pernambuco";
		cout << "Esses sao os EPIs entregues a este estado: PERNAMBUCO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 16)
	{
		Nestado[16] == "Piaui";
		cout << "Esses sao os EPIs entregues a este estado: PIAUI " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 17)
	{
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: RIO DE JANEIRO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 18)
	{
		Nestado[18] == "Rio Grande do Norte";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: RIO GRANDE DO NORTE " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 19)
	{
		Nestado[19] == "Rio Grande do Sul";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: RIO GRANDE DO SUL " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 20)
	{
		Nestado[20] == "Rondonia";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: RONDONIA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	else if (estado == 21)
	{
		Nestado[21] == "Roraima";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: RORAIMA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 22)
	{
		Nestado[22] == "Santa Catarina";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: SANTA CATARINA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 23)
	{
		Nestado[23] == "Sao Paulo";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: SAO PAULO " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 24)
	{
		Nestado[24] == "Serjipe";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: SERJIPE " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 25)
	{
		Nestado[25] == "Tocantins";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: TOCANTINS " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}
	if (estado == 26)
	{
		Nestado[26] == "Amapa";
		Nestado[17] == "Rio de Janeiro";
		cout << "Esses sao os EPIs entregues a este estado: AMAPA " << Nestado[estado] << endl;

		for (int i = 0; i < EpisNoEstado->NumDeEpis; i++)
		{
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
			cout << "Nome do Epi: " << EpisNoEstado->NomeDoEpiArmazenado[i] << endl;
			cout << "Quantidade do EPI armazenado:" << EpisNoEstado->QuantidadeArmazenada[i] << endl;
			cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		}
	}



}





int main()
{

	string Vacina = "Vacina";
	string Medicamento = "Medicamento";
	string Epi = "Epi";
	int LigaDesliga;
	int opcao;
	t_vacinas* ptr_vacina = &Vacinas[0];
	int VacinasCadastradas = 0;
	int EpisCadastradas = 0;
	int MedicamentosCadastrados = 0;
	int MaxV = 100;
	string estat;



	cout << "Digite '1' para comecar o programa ou '0' para fechar-lo:\n\n\nOBS: VOCE PODE DIGITAR 0 PARA FECHAR O PROGAMA EM QUALQUER MOMENTO QUE DESEJAR" << endl;
	cin >> LigaDesliga;
	if (LigaDesliga == 0)
	{
		return 0;
	}

	cout << "Ola, bem vindo ao aplicativo feito pelo Ministerio da Saude(MS) para o controle e distribuicao de insumos para Estados e Municipios" << endl;

	cout << "Digite sobre oque voce quer saber:\n Digite 'Vacina' para saber sobre as vacinas \n Digite 'Medicamento' para saber sobre os medicamentos\n Digite 'Epi' para saber sobre as Epis" << endl;

	string QuerSaber;



	cin >> QuerSaber;


	while (1) {



		if (QuerSaber == Vacina) {

			while (QuerSaber == Vacina)
			{



				cout << "Voce digitou 'vacina', quais das opcoes voce gostaria de seguir\n\n\n" << endl;

				cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";
				cout << "Digite 1 para cadastrar um insumo da opcao selecionada 'Vacina'\n"; // feito
				cout << "Digite 2 para consultar para consultar todos os insumos disponiveis no estoque da MS da opcao selecionada 'Vacina'\n"; //feito
				cout << "Digite 3 para consultar todos os insumos disponiveis no estoque da MS\n"; // Keys // feito
				cout << "Digite 4 para consultar a descricao dos insumos disponiveis no estoque da MS sobre a opcao selecionada 'Vacina'\n"; //feito
				cout << "Digite 5 para consultar a descricao dos insumos disponiveis no estoque da MS em geral\n"; // Keys // feito
				cout << "Digite 6 para consultar os insumos distribuidos para os Estados da opcao selecionada 'Vacina'\n"; //feito
				cout << "Digite 7 para consultar os insumos distribuidos para os Estados de todos os insumos\n"; // Eduardo // feito
				cout << "Digite 8 para consultar as informacoes dos insumos distribuidos para os Estados da opcao selecionada 'Vacina'\n"; //feito
				cout << "Digite 9 para consultar as informacoes dos insumos distribuidos para os Estados no geral\n"; // Eduardo // feito
				cout << "Digite 10 para consultar os insumos da opcao selecionada 'Vacina' enviados para um Estado\n";
				cout << "Digite 11 para consultar todos os insumos enviados para um Estado\n"; // Thales //feito
				cout << "Digite 12 para entregar/distribuir um insumo cadastrado do tipo selecionado 'Vacina' para um determinado Estado\n"; //feito
				cout << "Digite 13 para trocar a opcao selecionada atual 'Vacina'\n"; //feito
				cout << "Digite 0 para encerrar o progama\n"; // feito
				cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";


				cin >> opcao;

				int x;


				switch (opcao)
				{

				case 1:

					for (int i = 0; i < MaxV; i++)
					{
						if (i != VacinasCadastradas)
						{

						}

						else {

							CadastraVacina(&Vacinas[i]);
							VacinasCadastradas++;
							break;
						}

					}

					cout << "desejaria realizar outra acao agora?\n Digite '1' para SIM e '0' para NAO\n";
					cin >> opcao;

					if (opcao == 1)
					{
						continue;

					}
					else
					{
						return 0;
					}
					break;

				case 2:

					for (int i = 0; i < VacinasCadastradas; i++)
					{
						VisualizaVacinas(&Vacinas[i]);
					}
					cout << "Ok, agora que voce vizualizou as vacinas disponiveis no estoque da MS, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
					cin >> opcao;

					if (opcao == 1)
					{
						continue;

					}
					else
					{
						return 0;
					}


					break;

				case 3:

					for (int i = 0; i < VacinasCadastradas; i++)
					{
						VisualizaVacinas(&Vacinas[i]);
					}

					for (int i = 0; i < MedicamentosCadastrados; i++)
					{
						VisualizaMedicamentos(&Medicamentos[i]);
					}
					for (int i = 0; i < EpisCadastradas; i++)
					{
						VisualizaEpis(&Epis[i]);
					}
					cout << "Ok, agora que voce vizualizou os insumos disponiveis no estoque da MS, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
					cin >> opcao;

					if (opcao == 1)
					{
						continue;

					}
					else
					{
						return 0;
					}

					break;

				case 4:

					for (int i = 0; i < VacinasCadastradas; i++)
					{
						DescricaoVacina(&Vacinas[i]);
					}

					cout << "Ok, agora que voce vizualizou os detalhes das vacinas, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
					cin >> opcao;

					if (opcao == 1)
					{
						continue;

					}
					else
					{
					}
					return 0;



					break;

				case 5:

					for (int i = 0; i < VacinasCadastradas; i++)
					{
						DescricaoVacina(&Vacinas[i]);
					}
					for (int i = 0; i < MedicamentosCadastrados; i++)
					{
						DescricaoMedicamento(&Medicamentos[i]);
					}
					for (int i = 0; i < EpisCadastradas; i++)
					{
						DescricaoEpi(&Epis[i]);
					}
					cout << "Ok, agora que voce vizualizou os detalhes de todos os insumos disponiveis, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
					cin >> opcao;

					if (opcao == 1)
					{
						continue;

					}
					else
					{
					}
					return 0;

					break;

				case 6:
					for (int i = 0; i < 27; i++)
					{
						RetornaNomeDasVacinasNosEstados(&EVacina[i], i);
					}

					break;

				case 7:
					for (int i = 0; i < 27; i++)
					{
						ConsultaTodosOsInsumosNosEstados(&EVacina[i], &EEpi[i], &EMedicamento[i], i);
					}

					break;

				case 8:

					for (int i = 0; i < 27; i++)
					{
						RetornaDescricaoDaVacina(&EVacina[i], i);
					}

					break;

				case 9:
					for (int i = 0; i < 27; i++)
					{
						ConsultaAdescricaoTodosOsInsumosNosEstados(&EVacina[i], &EEpi[i], &EMedicamento[i], i);
					}

					break;

				case 10:
					
					cout << "Voce gostaria de consultar as vacinas enviadas para um estado?" << endl;
					cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
					cin >> x;

					if (x == 1) {

						int NumDoEstado;
						cout << "Digite a sigla em maiusculo do Estado que voce gostaria de consultar as vacinas" << endl;

						string E;
						cin >> E;

						if (E == "AC") {
							NumDoEstado = 0;
								ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "AL") {
							NumDoEstado = 1;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "AM") {
							NumDoEstado = 2;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "BA") {
							NumDoEstado = 3;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "CE") {
							NumDoEstado = 4;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "DF") {
							NumDoEstado = 5;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "ES") {
							NumDoEstado = 6;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "GO") {
							NumDoEstado = 7;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "MA") {
							NumDoEstado = 8;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "MT") {
							NumDoEstado = 9;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "MS") {
							NumDoEstado = 10;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "MG") {
							NumDoEstado = 11;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "PA") {
							NumDoEstado = 12;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "PB") {
							NumDoEstado = 13;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "PR") {
							NumDoEstado = 14;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "PE") {
							NumDoEstado = 15;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "PI") {
							NumDoEstado = 16;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "RJ") {
							NumDoEstado = 17;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "RN") {
							NumDoEstado = 18;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "RS") {
							NumDoEstado = 19;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "RO") {
							NumDoEstado = 20;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "RR") {
							NumDoEstado = 21;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "SC") {
							NumDoEstado = 22;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "SP") {
							NumDoEstado = 23;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "SE") {
							NumDoEstado = 24;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "TO") {
							NumDoEstado = 25;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else if (E == "AP") {
							NumDoEstado = 26;
							ConsultaVacinaNoEstado(&EVacina[NumDoEstado]);
						}
						else
						{
							cout << "Estado nao encontrado" << endl;
						}
					}

					break;

				case 11:
					cout << "Voce gostaria de consultar as vacinas enviadas para um estado?" << endl;
					cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
					cin >> x;

					if (x == 1) {

						int NumDoEstado;
						cout << "Digite a sigla em maiusculo do Estado que voce gostaria de consultar as vacinas" << endl;

						string E;
						cin >> E;

						if (E == "AC") {
							NumDoEstado = 0;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "AL") {
							NumDoEstado = 1;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "AM") {
							NumDoEstado = 2;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "BA") {
							NumDoEstado = 3;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "CE") {
							NumDoEstado = 4;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "DF") {
							NumDoEstado = 5;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "ES") {
							NumDoEstado = 6;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "GO") {
							NumDoEstado = 7;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "MA") {
							NumDoEstado = 8;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "MT") {
							NumDoEstado = 9;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "MS") {
							NumDoEstado = 10;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "MG") {
							NumDoEstado = 11;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "PA") {
							NumDoEstado = 12;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "PB") {
							NumDoEstado = 13;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "PR") {
							NumDoEstado = 14;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "PE") {
							NumDoEstado = 15;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "PI") {
							NumDoEstado = 16;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "RJ") {
							NumDoEstado = 17;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "RN") {
							NumDoEstado = 18;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "RS") {
							NumDoEstado = 19;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "RO") {
							NumDoEstado = 20;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "RR") {
							NumDoEstado = 21;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "SC") {
							NumDoEstado = 22;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "SP") {
							NumDoEstado = 23;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "SE") {
							NumDoEstado = 24;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "TO") {
							NumDoEstado = 25;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else if (E == "AP") {
							NumDoEstado = 26;
							ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
						}
						else
						{
							cout << "Estado nao encontrado" << endl;
						}
					}


					break;


				case 12:

					
					cout << "Voce gostaria de enviar uma vacina para o estoque de um Estado?" << endl;
					cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
					cin >> x;

					if (x == 1) {

						int NumDoEstado;
						cout << "Digite a sigla em maiusculo do Estado que voce gostaria de enviar uma vacina" << endl;

						string E;
						cin >> E;

						if (E == "AC") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[0]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "AL") {
							NumDoEstado = 1;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[1]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "AM") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[2]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "BA") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[3]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "CE") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[4]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "DF") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[5]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "ES") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[6]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "GO") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[7]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "MA") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[8]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "MT") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[9]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "MS") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[10]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "MG") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[11]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "PA") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[12]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "PB") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[13]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "PR") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[14]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "PE") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[15]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "PI") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[16]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "RJ") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[17]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "RN") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[18]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "RS") {
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[19]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "RO") {
							NumDoEstado = 20;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[20]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else if (E == "RR") {
							NumDoEstado = 21;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[21]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}
							}
						}
						else if (E == "SC") {
							NumDoEstado = 22;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[22]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}
							}
						}
						else if (E == "SP") {
							NumDoEstado = 23;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[23]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}
							}
						}
						else if (E == "SE") {
							NumDoEstado = 24;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[24]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}



							}
						}
						else if (E == "TO") {
							NumDoEstado = 25;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[25]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}
							}
						}
						else if (E == "AP") {
							NumDoEstado = 26;
							for (int i = 0; i < VacinasCadastradas; i++)
							{
								AdicionarNoEstado(&Vacinas[i], VacinasCadastradas, &EVacina[26]);
								cout << "gostaria de ir para a proxima vacina ? Digite '1' para SIM e '0' para NAO" << endl;
								cin >> x;
								if (!x)
								{
									break;
								}

							}
						}
						else
						{
							cout << "Estado nao encontrado" << endl;
						}
					}
					break;

				case 13:

					cout << "Digite sobre oque voce quer saber:\n Digite 'Vacina' para saber sobre as vacinas \n Digite 'Medicamento' para saber sobre os medicamentos\n Digite 'Epi' para saber sobre as Epis" << endl;

					cin >> QuerSaber;
					continue;

					break;


				case 0:

					return 0;
					break;

				}


			}


		}
		else if (QuerSaber == Medicamento) {

		while (QuerSaber == Medicamento) {

			cout << "Voce digitou 'Medicamento', quais dos opcoes voce gostaria de seguir\n\n" << endl;

			cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";
			cout << "Digite 1 para cadastrar um insumo da opcao selecionada 'Medicamento'\n"; // feito
			cout << "Digite 2 para consultar para consultar todos os insumos disponiveis no estoque da MS da opcao selecionada 'Medicamento'\n"; //feito
			cout << "Digite 3 para consultar todos os insumos disponiveis no estoque da MS\n"; // Keys
			cout << "Digite 4 para consultar a descricao dos insumos disponiveis no estoque da MS sobre a opcao selecionada 'Medicamento'\n"; //feito
			cout << "Digite 5 para consultar a descricao dos insumos disponiveis no estoque da MS em geral\n"; // Keys
			cout << "Digite 6 para consultar os insumos distribuidos para os Estados da opcao selecionada 'Medicamento'\n"; //feito
			cout << "Digite 7 para consultar os insumos distribuidos para os Estados de todos os insumos\n"; // Eduardo
			cout << "Digite 8 para consultar as informacoes dos insumos distribuidos para os Estados da opcao selecionada 'Medicamento'\n"; //feito
			cout << "Digite 9 para consultar os informacoes dos insumos distribuidos para os Estados no geral\n"; // Eduardo
			cout << "Digite 10 para consultar os insumos da opcao selecionada 'Medicamento' enviados para um Estado\n";
			cout << "Digite 11 para consultar todos os insumos enviados para um Estado\n"; // Thales
			cout << "Digite 12 para entregar/distribuir um insumo cadastrado do tipo selecionado 'Medicamento' para um determinado Estado\n"; //feito
			cout << "Digite 13 para trocar a opcao selecionada atual 'Medicamento'\n"; //feito
			cout << "Digite 0 para encerrar o programa\n"; // feito
			cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";

			cin >> opcao;

			int x;


			switch (opcao)
			{

			case 1:

				for (int i = 0; i < MaxV; i++)
				{
					if (i != MedicamentosCadastrados)
					{

					}

					else {

						CadastraMedicamento(&Medicamentos[i]);
						MedicamentosCadastrados++;
						break;
					}
				}

				cout << "desejaria realizar outra acao agora?\n Digite '1' para SIM e '0' para NAO\n";
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
					return 0;
				}
				break;

			case 2:

				for (int i = 0; i < MedicamentosCadastrados; i++)
				{
					VisualizaMedicamentos(&Medicamentos[i]);
				}
				cout << "Ok, agora que voce vizualizou os medicamentos disponiveis no estoque da MS, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
					return 0;
				}


				break;

			case 3:

				for (int i = 0; i < VacinasCadastradas; i++)
				{
					VisualizaVacinas(&Vacinas[i]);
				}

				for (int i = 0; i < MedicamentosCadastrados; i++)
				{
					VisualizaMedicamentos(&Medicamentos[i]);
				}
				for (int i = 0; i < EpisCadastradas; i++)
				{
					VisualizaEpis(&Epis[i]);
				}
				cout << "Ok, agora que voce vizualizou os insumos disponiveis no estoque da MS, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
					return 0;
				}

				break;

			case 4:

				for (int i = 0; i < MedicamentosCadastrados; i++)
				{
					DescricaoMedicamento(&Medicamentos[i]);
				}

				cout << "Ok, agora que voce vizualizou os detalhes dos medicamentos, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
				}
				return 0;



				break;

			case 5:
				for (int i = 0; i < VacinasCadastradas; i++)
				{
					DescricaoVacina(&Vacinas[i]);
				}
				for (int i = 0; i < MedicamentosCadastrados; i++)
				{
					DescricaoMedicamento(&Medicamentos[i]);
				}
				for (int i = 0; i < EpisCadastradas; i++)
				{
					DescricaoEpi(&Epis[i]);
				}
				cout << "Ok, agora que voce vizualizou os detalhes de todos os insumos disponiveis, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
				}
				return 0;

				break;

			case 6:
				for (int i = 0; i < 27; i++)
				{
					RetornaNomeDosMedicamentosNosEstados(&EMedicamento[i], i);
				}

				break;

			case 7:
				for (int i = 0; i < 27; i++)
				{
					ConsultaTodosOsInsumosNosEstados(&EVacina[i], &EEpi[i], &EMedicamento[i], i);
				}

				break;

			case 8:

				for (int i = 0; i < 27; i++)
				{
					RetornaDescricaoDoMedicamento(&EMedicamento[i], i);
				}

				break;

			case 9:
				for (int i = 0; i < 27; i++)
				{
					ConsultaAdescricaoTodosOsInsumosNosEstados(&EVacina[i], &EEpi[i], &EMedicamento[i], i);
				}

				break;

			case 10:

				cout << "Voce gostaria de consultar os medicamentos enviadas para um estado?" << endl;
				cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
				cin >> x;

				if (x == 1) {

					int NumDoEstado;
					cout << "Digite a sigla em maiusculo do Estado que voce gostaria de consultar os medicamentos" << endl;

					string E;
					cin >> E;

					if (E == "AC") {
						NumDoEstado = 0;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "AL") {
						NumDoEstado = 1;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "AM") {
						NumDoEstado = 2;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "BA") {
						NumDoEstado = 3;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "CE") {
						NumDoEstado = 4;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "DF") {
						NumDoEstado = 5;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "ES") {
						NumDoEstado = 6;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "GO") {
						NumDoEstado = 7;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "MA") {
						NumDoEstado = 8;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "MT") {
						NumDoEstado = 9;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "MS") {
						NumDoEstado = 10;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "MG") {
						NumDoEstado = 11;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "PA") {
						NumDoEstado = 12;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "PB") {
						NumDoEstado = 13;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "PR") {
						NumDoEstado = 14;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "PE") {
						NumDoEstado = 15;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "PI") {
						NumDoEstado = 16;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "RJ") {
						NumDoEstado = 17;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "RN") {
						NumDoEstado = 18;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "RS") {
						NumDoEstado = 19;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "RO") {
						NumDoEstado = 20;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "RR") {
						NumDoEstado = 21;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "SC") {
						NumDoEstado = 22;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "SP") {
						NumDoEstado = 23;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "SE") {
						NumDoEstado = 24;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "TO") {
						NumDoEstado = 25;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else if (E == "AP") {
						NumDoEstado = 26;
						ConsultaMedicamentoNoEstado(&EMedicamento[NumDoEstado]);
					}
					else
					{
						cout << "Estado nao encontrado" << endl;
					}
				}

				break;
			case 11:
				cout << "Voce gostaria de consultar as vacinas enviadas para um estado?" << endl;
				cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
				cin >> x;

				if (x == 1) {

					int NumDoEstado;
					cout << "Digite a sigla em maiusculo do Estado que voce gostaria de consultar as vacinas" << endl;

					string E;
					cin >> E;

					if (E == "AC") {
						NumDoEstado = 0;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "AL") {
						NumDoEstado = 1;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "AM") {
						NumDoEstado = 2;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "BA") {
						NumDoEstado = 3;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "CE") {
						NumDoEstado = 4;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "DF") {
						NumDoEstado = 5;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "ES") {
						NumDoEstado = 6;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "GO") {
						NumDoEstado = 7;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MA") {
						NumDoEstado = 8;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MT") {
						NumDoEstado = 9;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MS") {
						NumDoEstado = 10;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MG") {
						NumDoEstado = 11;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PA") {
						NumDoEstado = 12;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PB") {
						NumDoEstado = 13;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PR") {
						NumDoEstado = 14;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PE") {
						NumDoEstado = 15;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PI") {
						NumDoEstado = 16;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RJ") {
						NumDoEstado = 17;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RN") {
						NumDoEstado = 18;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RS") {
						NumDoEstado = 19;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RO") {
						NumDoEstado = 20;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RR") {
						NumDoEstado = 21;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "SC") {
						NumDoEstado = 22;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "SP") {
						NumDoEstado = 23;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "SE") {
						NumDoEstado = 24;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "TO") {
						NumDoEstado = 25;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "AP") {
						NumDoEstado = 26;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else
					{
						cout << "Estado nao encontrado" << endl;
					}
				}


				break;

			case 12:


				cout << "Voce gostaria de enviar uma Medicamento para o estoque de um Estado?" << endl;
				cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
				cin >> x;

				if (x == 1) {

					int NumDoEstado;
					cout << "Digite a sigla em maiusculo do Estado que voce gostaria de enviar uma Medicamento" << endl;

					string E;
					cin >> E;

					if (E == "AC") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[0]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "AL") {
						NumDoEstado = 1;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[1]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "AM") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[2]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "BA") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[3]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "CE") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[4]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "DF") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[5]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "ES") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[6]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "GO") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[7]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MA") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[8]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MT") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[9]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MS") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[10]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MG") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[11]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PA") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[12]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PB") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[13]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PR") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[14]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PE") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[15]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PI") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[16]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RJ") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[17]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RN") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[18]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RS") {
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[19]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RO") {
						NumDoEstado = 20;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[20]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RR") {
						NumDoEstado = 21;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[21]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "SC") {
						NumDoEstado = 22;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[22]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "SP") {
						NumDoEstado = 23;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[23]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "SE") {
						NumDoEstado = 24;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[24]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}



						}
					}
					else if (E == "TO") {
						NumDoEstado = 25;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[25]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "AP") {
						NumDoEstado = 26;
						for (int i = 0; i < MedicamentosCadastrados; i++)
						{
							AdicionarMedicamentoNoEstado(&Medicamentos[i], MedicamentosCadastrados, &EMedicamento[26]);
							cout << "gostaria de ir para o proximo Medicamento ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else
					{
						cout << "Estado nao encontrado" << endl;
					}
				}
				break;

			case 13:

				cout << "Digite sobre oque voce quer saber:\n Digite 'Medicamento' para saber sobre os medicamentos \n Digite 'Vacina' para saber sobre os medicamentos\n Digite 'Epi' para saber sobre os Epis" << endl;

				cin >> QuerSaber;
				continue;

				break;


			case 0:

				return 0;
				break;

			}


		}
		}





		else if (QuerSaber == Epi) {

		while (QuerSaber == Epi)
		{



			cout << "Voce digitou 'Epi', quais das opcoes voce gostaria de seguir\n\n" << endl;

			cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";
			cout << "- Digite 1 para cadastrar um insumo da opcao selecionada 'EPI'\n";
			cout << "- Digite 2 para consultar para consultar todos os insumos disponiveis no estoque da MS da opcao selecionada 'EPI'\n";
			cout << "- Digite 3 para consultar todos os insumos disponiveis no estoque da MS\n";
			cout << "- Digite 4 para consultar a descricao dos insumos disponiveis no estoque da MS sobre a opcao selecionada 'EPI'\n"; //
			cout << "- Digite 5 para consultar a descricao dos insumos disponiveis no estoque da MS em geral\n";
			cout << "- Digite 6 para consultar os insumos distribuidos para os Estados da opcao selecionada 'EPI'\n"; //
			cout << "- Digite 7 para consultar os insumos distribuidos para os Estados de todos os insumos\n";
			cout << "- Digite 8 para consultar as informacoes dos insumos distribuidos para os Estados da opcao selecionada 'EPI'\n";
			cout << "- Digite 9 para consultar as informacoes dos insumos distribuidos para os Estados no geral\n";
			cout << "- Digite 10 para consultar os insumos da opcao selecionada 'EPI' enviados para um Estado\n";
			cout << "- Digite 11 para consultar todos os insumos enviados para um Estado\n";
			cout << "- Digite 12 para entregar/distribuir um insumo cadastrado do tipo selecionado 'Epi' para um determinado Estado\n"; //
			cout << "- Digite 13 para trocar a opcao selecionada atual 'EPI'\n";
			cout << "- Digite 0 para encerrar o progama\n\n\n\n";
			cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n";

			cin >> opcao;
			int x;

			switch (opcao)
			{

			case 1:

				for (int i = 0; i < MaxV; i++)
				{
					if (i != EpisCadastradas)
					{

					}

					else {
						CadastraEpi(&Epis[i]);
						EpisCadastradas++;
						break;
					}

				}

				cout << "Desejaria realizar outra acao agora?\n Digite '1' para SIM e '0' para NAO\n";
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
					return 0;
				}
				break;

			case 2:

				for (int i = 0; i < EpisCadastradas; i++)
				{
					VisualizaEpis(&Epis[i]);
				}
				cout << "Ok, agora que voce vizualizou os EPIs disponiveis no estoque da MS, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
					return 0;
				}


				break;

			case 3:

				for (int i = 0; i < VacinasCadastradas; i++)
				{
					VisualizaVacinas(&Vacinas[i]);
				}

				for (int i = 0; i < MedicamentosCadastrados; i++)
				{
					VisualizaMedicamentos(&Medicamentos[i]);
				}
				for (int i = 0; i < EpisCadastradas; i++)
				{
					VisualizaEpis(&Epis[i]);
				}
				cout << "Ok, agora que voce vizualizou os insumos disponiveis no estoque da MS, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
					return 0;
				}

				break;

			case 4:

				for (int i = 0; i < EpisCadastradas; i++)
				{
					DescricaoEpi(&Epis[i]);
				}

				cout << "Ok, agora que voce vizualizou os detalhes dos EPIs, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
				}
				return 0;



				break;

			case 5:

				for (int i = 0; i < VacinasCadastradas; i++)
				{
					DescricaoVacina(&Vacinas[i]);
				}
				for (int i = 0; i < MedicamentosCadastrados; i++)
				{
					DescricaoMedicamento(&Medicamentos[i]);
				}
				for (int i = 0; i < EpisCadastradas; i++)
				{
					DescricaoEpi(&Epis[i]);
				}
				cout << "Ok, agora que voce vizualizou os detalhes de todos os insumos disponiveis, gostaria de fazer outra acao?\nDigite '1' para SIM e '0' para NAO" << endl;
				cin >> opcao;

				if (opcao == 1)
				{
					continue;

				}
				else
				{
				}
				return 0;



				break;

			case 6:
				for (int i = 0; i < 27; i++)
				{
					RetornaNomeEpiNosEstados(&EEpi[i], i);
				}

				break;

			case 7:
				for (int i = 0; i < 27; i++)
				{
					ConsultaTodosOsInsumosNosEstados(&EVacina[i], &EEpi[i], &EMedicamento[i], i);
				}

				break;

			case 8:

				for (int i = 0; i < 27; i++)
				{
					RetornaDescricaoDoEpi(&EEpi[i], i);
				}

				break;

			case 9:
				for (int i = 0; i < 27; i++)
				{
					ConsultaAdescricaoTodosOsInsumosNosEstados(&EVacina[i], &EEpi[i], &EMedicamento[i], i);
				}

				break;

			case 10:

				cout << "Voce gostaria de consultar os EPIs enviadas para um estado?" << endl;
				cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
				cin >> x;

				if (x == 1) {

					int NumDoEstado;
					cout << "Digite a sigla em maiusculo do Estado que voce gostaria de consultar os EPIs" << endl;

					string E;
					cin >> E;

					if (E == "AC") {
						NumDoEstado = 0;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "AL") {
						NumDoEstado = 1;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "AM") {
						NumDoEstado = 2;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "BA") {
						NumDoEstado = 3;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "CE") {
						NumDoEstado = 4;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "DF") {
						NumDoEstado = 5;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "ES") {
						NumDoEstado = 6;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "GO") {
						NumDoEstado = 7;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "MA") {
						NumDoEstado = 8;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "MT") {
						NumDoEstado = 9;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "MS") {
						NumDoEstado = 10;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "MG") {
						NumDoEstado = 11;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "PA") {
						NumDoEstado = 12;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "PB") {
						NumDoEstado = 13;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "PR") {
						NumDoEstado = 14;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "PE") {
						NumDoEstado = 15;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "PI") {
						NumDoEstado = 16;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "RJ") {
						NumDoEstado = 17;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "RN") {
						NumDoEstado = 18;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "RS") {
						NumDoEstado = 19;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "RO") {
						NumDoEstado = 20;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "RR") {
						NumDoEstado = 21;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "SC") {
						NumDoEstado = 22;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "SP") {
						NumDoEstado = 23;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "SE") {
						NumDoEstado = 24;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "TO") {
						NumDoEstado = 25;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else if (E == "AP") {
						NumDoEstado = 26;
						ConsultaEpiNoEstado(&EEpi[NumDoEstado]);
					}
					else
					{
						cout << "Estado nao encontrado" << endl;
					}
				}

				break;

			case 11:
				cout << "Voce gostaria de consultar as vacinas enviadas para um estado?" << endl;
				cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
				cin >> x;

				if (x == 1) {

					int NumDoEstado;
					cout << "Digite a sigla em maiusculo do Estado que voce gostaria de consultar as vacinas" << endl;

					string E;
					cin >> E;

					if (E == "AC") {
						NumDoEstado = 0;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "AL") {
						NumDoEstado = 1;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "AM") {
						NumDoEstado = 2;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "BA") {
						NumDoEstado = 3;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "CE") {
						NumDoEstado = 4;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "DF") {
						NumDoEstado = 5;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "ES") {
						NumDoEstado = 6;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "GO") {
						NumDoEstado = 7;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MA") {
						NumDoEstado = 8;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MT") {
						NumDoEstado = 9;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MS") {
						NumDoEstado = 10;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "MG") {
						NumDoEstado = 11;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PA") {
						NumDoEstado = 12;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PB") {
						NumDoEstado = 13;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PR") {
						NumDoEstado = 14;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PE") {
						NumDoEstado = 15;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "PI") {
						NumDoEstado = 16;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RJ") {
						NumDoEstado = 17;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RN") {
						NumDoEstado = 18;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RS") {
						NumDoEstado = 19;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RO") {
						NumDoEstado = 20;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "RR") {
						NumDoEstado = 21;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "SC") {
						NumDoEstado = 22;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "SP") {
						NumDoEstado = 23;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "SE") {
						NumDoEstado = 24;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "TO") {
						NumDoEstado = 25;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else if (E == "AP") {
						NumDoEstado = 26;
						ConsultaTodosOsInsumosPorEstados(&EVacina[NumDoEstado], &EEpi[NumDoEstado], &EMedicamento[NumDoEstado], NumDoEstado);
					}
					else
					{
						cout << "Estado nao encontrado" << endl;
					}
				}


				break;

			case 12:

				int x;
				cout << "Gostaria de enviar um EPI para o estoque de um Estado?" << endl;
				cout << "Digite '1' para SIM e '2' para NAO" << endl << endl;
				cin >> x;

				if (x == 1) {

					int NumDoEstado;

					cout << "Digite a sigla em maiusculo do Estado que voce gostaria de enviar um Epi" << endl;

					string E;
					cin >> E;

					if (E == "AC") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[0]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "AL") {
						NumDoEstado = 1;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[1]);
							cout << "gostaria de ir para o proximo EPI  ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "AM") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[2]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "BA") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[3]);
							cout << "gostaria de ir para o proximo EPI  ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "CE") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[4]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "DF") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[5]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "ES") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[6]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "GO") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[7]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MA") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[8]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MT") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[9]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MS") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[10]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "MG") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[11]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PA") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[12]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PB") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[13]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PR") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[14]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PE") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[15]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "PI") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[16]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RJ") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[17]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RN") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[18]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RS") {
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[19]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RO") {
						NumDoEstado = 20;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[20]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else if (E == "RR") {
						NumDoEstado = 21;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[21]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "SC") {
						NumDoEstado = 22;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[22]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "SP") {
						NumDoEstado = 23;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[23]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "SE") {
						NumDoEstado = 24;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[24]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}



						}
					}
					else if (E == "TO") {
						NumDoEstado = 25;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[25]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}
						}
					}
					else if (E == "AP") {
						NumDoEstado = 26;
						for (int i = 0; i < EpisCadastradas; i++)
						{
							AdicionarEpiNoEstado(&Epis[i], EpisCadastradas, &EEpi[26]);
							cout << "gostaria de ir para o proximo EPI ? Digite '1' para SIM e '0' para NAO" << endl;
							cin >> x;
							if (!x)
							{
								break;
							}

						}
					}
					else
					{
						cout << "Estado nao encontrado" << endl;
					}
				}
				break;

			case 13:
				cout << "Digite sobre oque voce quer saber:\n Digite 'Vacina' para saber sobre as vacinas \n Digite 'Medicamento' para saber sobre os medicamentos\n Digite 'Epi' para saber sobre as Epis" << endl;

				cin >> QuerSaber;
				continue;

				break;


			case 0:

				return 0;
				break;

			}
		}
		}
	}
	return 0;
}
