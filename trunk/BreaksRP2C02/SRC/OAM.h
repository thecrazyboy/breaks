#define OAM_CAS_0   (ppu->OAM_CAS[0])
#define OAM_CAS_1   (ppu->OAM_CAS[1])
#define OAM_CAS_2   (ppu->OAM_CAS[2])
#define OAM_CAS_3   (ppu->OAM_CAS[3])
#define OAM_CAS_4   (ppu->OAM_CAS[4])
#define OAM_CAS_5   (ppu->OAM_CAS[5])
#define OAM_CAS_6   (ppu->OAM_CAS[6])
#define OAM_CAS_7   (ppu->OAM_CAS[7])
#define OAM_CAS_Z   (ppu->OAM_CAS[8])

void OAM_RAS (Context2C02 *ppu);
void OAM_CAS (Context2C02 *ppu);
void OAM_CTRL (Context2C02 *ppu);
void OAM_BUF (Context2C02 *ppu);
