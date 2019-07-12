#pragma once
#include "../APIServer.h"

namespace MoreJeeAPI
{
	namespace MoreJee
	{
		//��Ʒ��ҳ��ѯ����
		struct ProductQuery
		{
			short page;
			short pageSize;
			wstring search;
		};

		//��Ʒ��ҳ���ص��Ӳ���
		struct ProductListDTO
		{
			wstring id;
			wstring name;
			wstring icon;
			wstring description;
			wstring categoryId;
			wstring categoryName;
			wstring brand;
			wstring unit;
			wstring price;
			wstring partnerPrice;
			wstring purchasePrice;
			float maxPrice;
			float minPrice;
			float maxPartnerPrice;
			float minPartnerPrice;
			float maxPurchasePrice;
			float minPurchasePrice;
		};

		//��Ʒ��ҳ���ص��ܲ���
		struct ProductQueryDTO
		{
			int total;
			vector<ProductListDTO> data;
		};

		//��Ʒ������Դ���󷵻صĹ���Ӳ���
		struct ProductSpecListDTO
		{
			wstring id;
			wstring name;
			wstring icon;
			wstring description;
			float price;
			float partnerPrice;
			float purchasePrice;
		};

		//��Ʒ������Դ���󷵻ص��ܲ���
		struct ProductIdentityQueryDTO
		{
			wstring id;
			wstring name;
			wstring icon;
			wstring description;
			wstring categoryId;
			wstring categoryName;
			wstring brand;
			wstring unit;
			wstring price;
			wstring partnerPrice;
			wstring purchasePrice;
			float maxPrice;
			float minPrice;
			float maxPartnerPrice;
			float minPartnerPrice;
			float maxPurchasePrice;
			float minPurchasePrice;
			vector<ProductSpecListDTO> specifications;
		};

		//������Ʒ����
		struct ProductCreateCommand
		{
			wstring name;
			wstring icon;
			wstring description;
			wstring categoryId;
			wstring brand;
			wstring unit;
		};

		//�༭��Ʒ������Ϣ����
		struct ProductBasicInfoPatchCommand
		{
			wstring name;
			wstring icon;
			wstring description;
			wstring brand;
			wstring unit;

			vector<HttpPatchData> _GetPatchData()
			{
				vector<HttpPatchData> data;
				HttpPatchData n1{ L"add",L"name",name };
				//HttpPatchData n2{ L"add",L"icon",icon };
				HttpPatchData n3{ L"add",L"description",description };
				HttpPatchData n4{ L"add",L"brand",brand };
				HttpPatchData n5{ L"add",L"unit",unit };
				data.push_back(n1);
				//data.push_back(n2);
				data.push_back(n3);
				data.push_back(n4);
				data.push_back(n5);
				return data;
			}
		};

		class MOREJEEAPICLIENT_API ProductServer :protected APIServer
		{
		private:
			ProductServer();
			ProductServer(const ProductServer& s);
		public:
			static ProductServer& Instance();//��ȡ��ʵ������
			bool Query(const ProductQuery& query, ProductQueryDTO& result, HttpErrorMessage* error = nullptr);//��ҳ��ѯ����
			bool GetById(const wstring& id, ProductIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);//������Դ��ѯ����
			bool Create(const ProductCreateCommand& command, ProductIdentityQueryDTO& result, HttpErrorMessage* error = nullptr);//������Դ����
			bool Update(const wstring& id, const vector<HttpPatchData>& command, HttpErrorMessage* error = nullptr);//�޸���Դ����
			bool Delete(const wstring& id, HttpErrorMessage* error = nullptr);//ɾ����Դ����
		};
	}
}

