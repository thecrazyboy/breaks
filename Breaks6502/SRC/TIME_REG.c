// T-step counter
#include "Breaks6502.h"
#include "Breaks6502Private.h"

// sync is raised only during T1X stage. Fuck it.. I better explain it on russian:
// ������ ���: ������ ���������� ����������� �� 2 �����. ��������� ������� ����
// ������� (SYNC) ����� �� �������� ���������� ������� �����. ��� ������ ������ ����� 
// ���������� ������ ������������ ����������, ���� ����� ������� ��������� �������� ������
// � ������� ����������, ������� ����������� ����� 2� ������.
// ������ ��������� �� ����� ���������� ����� �������� �� ��������� � �������������.
// ������ ������ SYNC ������������ �������� ������ �������� �� �������������� ��������� (����� 2� ������)

int TcountRegister (Context6502 * cpu)
{
    char TR[4];     // Output register value.
    int i, out;

    if ( cpu->PHI2 ) cpu->TRSync = cpu->sync;

    out = BIT(~cpu->TRSync);
    for (i=0; i<4; i++)
    {
        if ( cpu->PHI1 ) {
            if (cpu->ready) cpu->TRin[i] = out;
            else cpu->TRin[i] = BIT(~cpu->TRout[i]);
        }
        TR[i] = BIT(~(~cpu->TRin[i] & ~cpu->TRES));
        if ( cpu->PHI2 ) cpu->TRout[i] = BIT(~TR[i]);
        out = BIT(~cpu->TRout[i]);
    }

    cpu->Tcount = (TR[3] << 3) | (TR[2] << 2) | (TR[1] << 1) | (TR[0] << 0);
    return cpu->Tcount;
}
