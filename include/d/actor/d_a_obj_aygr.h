#ifndef D_A_OBJ_AYGR_H
#define D_A_OBJ_AYGR_H

#include "d/d_bg_s_movebg_actor.h"
#include "d/d_a_obj.h"                       // for daObj::PrmAbstract
#include "SSystem/SComponent/c_phase.h"      // for request_of_phase_process_class

namespace daObjAygr {
    class Act_c : public dBgS_MoveBgActor {
    public:
        u8 prm_get_mdl() const { return daObj::PrmAbstract(this, PRM_MDL_W, PRM_MDL_S); }

        virtual BOOL CreateHeap();
        virtual BOOL Create();
        cPhs_State Mthd_Create();
        virtual BOOL Delete();
        BOOL Mthd_Delete();
        void set_mtx();
        void init_mtx();
        virtual BOOL Execute(Mtx**);
        virtual BOOL Draw();

        enum Prm_e {
            PRM_MDL_W = 1,    // width=1, from asm (li r4, 0x1)
            PRM_MDL_S = 0,    // shift=0, from asm (li r5, 0x0)
        };

        static Mtx M_tmp_mtx;
        static const char M_arcname[];

    public:
        /* 0x2C8 */ request_of_phase_process_class mPhs;
        /* 0x2D0 */ J3DModel* mpModel;
        /* 0x2D4 */ J3DModel* field_0x2d4;
        /* 0x2D8 */ dBgW* field_0x2d8;
        /* 0x2DC */ Mtx field_0x2dc;        // 48 bytes, ends at 0x30C
        /* 0x30C */ u8 field_0x30c;
    };
};

#endif /* D_A_OBJ_AYGR_H */
