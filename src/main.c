#include "modding.h"
#include "ultra64.h"
#include "enums.h"
#include "common_structs.h"

extern Actor *gCurrentPlayer;
extern u8 cc_player_index;

void func_global_asm_80602B60(s32 arg0, u8 arg1);
void func_global_asm_806CA2AC(void);
void func_global_asm_806C9F74(Actor *arg0);
void func_global_asm_806CF42C(Actor *arg0);
void playAnimation(Actor *arg0, s32 arg2);
s16 func_global_asm_80672A70(s16 arg0, s16 arg1);
s16 func_global_asm_80665DE0(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_global_asm_80627948(Actor *arg0, u8 arg1, u8 arg2, u8 arg3);

// danceGB
/*
  Keeping comments to show what's changed
  from the vanilla func for debugging purposes.
*/
RECOMP_PATCH void func_global_asm_806EFB4C(void) {
  func_global_asm_80602B60(0x6B, 0); // cancelMusic
  func_global_asm_806CA2AC(); // ResetShockwaveTimer
  func_global_asm_806C9F74(gCurrentPlayer); // FUN_806c9f74 (??)
  func_global_asm_806CF42C(gCurrentPlayer); // DestroyHeldObject
  playAnimation(gCurrentPlayer, 0x5B);
  gCurrentPlayer->control_state = 0; // Changed from 0x70
  gCurrentPlayer->control_state_progress = 0;
  /* if/else reversed in decomp
    if (gCurrentPlayer->unkFC) {
      gCurrentPlayer->y_rotation = func_global_asm_80672A70(gCurrentPlayer->unkF4, gCurrentPlayer->unkF6); // FUN_80672a70 (??)
    } else {
      gCurrentPlayer->y_rotation = func_global_asm_80665DE0(
        character_change_array[cc_player_index].look_at_eye_x,
        character_change_array[cc_player_index].look_at_eye_z,
        gCurrentPlayer->x_position,
        gCurrentPlayer->z_position
      ); // getAngleBetweenPoints
    }
    func_global_asm_80627948(gCurrentPlayer, 0x15, 0x1F, 5); // FUN_80627948 (??)
  */
}
