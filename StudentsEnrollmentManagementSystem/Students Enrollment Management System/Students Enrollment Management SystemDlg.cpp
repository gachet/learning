
// Students Enrollment Management SystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Students Enrollment Management System.h"
#include "Students Enrollment Management SystemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

// �Ի�������
    enum { IDD = IDD_ABOUTBOX };

    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
    DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentsEnrollmentManagementSystemDlg �Ի���



CStudentsEnrollmentManagementSystemDlg::CStudentsEnrollmentManagementSystemDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CStudentsEnrollmentManagementSystemDlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CStudentsEnrollmentManagementSystemDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TAB1, m_tabctrl);
}

BEGIN_MESSAGE_MAP(CStudentsEnrollmentManagementSystemDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_COMMAND(ID_32776_About, &CStudentsEnrollmentManagementSystemDlg::On32776About)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CStudentsEnrollmentManagementSystemDlg::OnTcnSelchangeTab1)
    ON_COMMAND(ID_32772_Exit, &CStudentsEnrollmentManagementSystemDlg::On32772Exit)
END_MESSAGE_MAP()


// CStudentsEnrollmentManagementSystemDlg ��Ϣ��������

BOOL CStudentsEnrollmentManagementSystemDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // ��������...���˵������ӵ�ϵͳ�˵��С�
    CMenu* cMenu = new CMenu;
    cMenu->LoadMenu(MAKEINTRESOURCE(IDR_MENU1));
    this->SetMenu(cMenu);

    // IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);		// ����Сͼ��

    // TODO:  �ڴ����Ӷ���ĳ�ʼ������
    m_tabctrl.InsertItem(0, L"ѧ������");
    m_tabctrl.InsertItem(1, L"�γ̹���");
    m_tabctrl.InsertItem(2, L"�༶����");

    m_page_students.Create(IDD_DIALOG_STUDENTS, &m_tabctrl);
    m_page_courses.Create(IDD_DIALOG_COURSES, &m_tabctrl);
    m_page_classes.Create(IDD_DIALOG_CLASSES, &m_tabctrl);

    CRect rc;
    m_tabctrl.GetClientRect(rc);
    rc.top += 22;
    rc.bottom -= 2;
    rc.left += 0;
    rc.right -= 0;
    m_page_students.MoveWindow(&rc);
    m_page_courses.MoveWindow(&rc);
    m_page_classes.MoveWindow(&rc);

    pDialog[0] = &m_page_students;
    pDialog[1] = &m_page_courses;
    pDialog[2] = &m_page_classes;

    //��ʾ��ʼҳ��
    pDialog[0]->ShowWindow(SW_SHOW);
    pDialog[1]->ShowWindow(SW_HIDE);
    pDialog[2]->ShowWindow(SW_HIDE);

    //���浱ǰѡ��
    m_CurSelTab = 0;

    DoDataInit();

    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CStudentsEnrollmentManagementSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStudentsEnrollmentManagementSystemDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CStudentsEnrollmentManagementSystemDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void CStudentsEnrollmentManagementSystemDlg::On32776About()
{
    CAboutDlg dlg;
    dlg.DoModal();
}


void CStudentsEnrollmentManagementSystemDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
    pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
    m_CurSelTab = m_tabctrl.GetCurSel();
    pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
    *pResult = 0;
}


void CStudentsEnrollmentManagementSystemDlg::On32772Exit()
{
    this->SendMessage(WM_CLOSE);
}

void CStudentsEnrollmentManagementSystemDlg::DoDataInit()
{
    //If you want to send message to another object, HWND must be defined.
    ::SendMessage(m_page_students, WM_Students_Data_Init, 0, reinterpret_cast<LPARAM>(&control));
    ::SendMessage(m_page_courses, WM_Courses_Data_Init, 0, reinterpret_cast<LPARAM>(&control));
    ::SendMessage(m_page_classes, WM_Classes_Data_Init, 0, reinterpret_cast<LPARAM>(&control));
}