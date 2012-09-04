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

int TcountRegister (Context6502 * cpu, int sync, int ready, int TRES)
{
    char TR[4];     // Output register value.
    int i, out;

    if ( cpu->PHI2 ) cpu->TRSync = sync;

    out = BIT(~cpu->TRSync);
    for (i=0; i<4; i++)
    {
        if ( cpu->PHI1 ) {
            if (ready) cpu->TRin[i] = out;
            else cpu->TRin[i] = BIT(~cpu->TRout[i]);
        }
        TR[i] = BIT(~(~cpu->TRin[i] & ~TRES));
        if ( cpu->PHI2 ) cpu->TRout[i] = BIT(~TR[i]);
        out = BIT(~cpu->TRout[i]);
    }

    return (TR[3] << 3) | (TR[2] << 2) | (TR[1] << 1) | (TR[0] << 0);
}
