SECTION code_user

EXTERN AYFX_INIT
EXTERN AYFX_PLAY
EXTERN AYFX_FRAME

PUBLIC _afx_init
PUBLIC _afx_play
PUBLIC _afx_frame
PUBLIC _afx_play_isr

_afx_init:
    ; hl contains afx bank address
    di
    push af
    push bc
    push de
    push hl
    push ix
    call AYFX_INIT
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ei
    ret

_afx_play:
    di
    push af
    push bc
    push de
    push hl
    push ix
    ld a,l
    call AYFX_PLAY
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ei
    ret

_afx_frame:
    di
    push af
    push bc
    push de
    push hl
    push ix
    call AYFX_FRAME
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ei
    ret

_afx_play_isr:
    di
    push af
    push bc
    push de
    push hl
    ex af,af'
    exx
    push af
    push bc
    push de
    push hl
    push ix
    push iy

    ; Check if afx_play_isr is enabled.
    ld a,(_afx_play_isr_enabled)
    or a
    jr z,end

    ; Check if 60 Hz mode.
    ld a,5
    ld bc,$243B
    out (c),a
    inc b
    in a,(c)
    bit 2,a
    jr z,play

    ; Compensate for 60 Hz mode by skip calling AYFX_FRAME every 6th frame.
    ld a,(_frame_counter)
    cp 5
    jr nz,inc_frame_counter
    ld a,0
    ld (_frame_counter),a
    jr end

inc_frame_counter:
    ld hl,_frame_counter
    inc (hl)

play:
    call AYFX_FRAME

end:
    pop iy
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    exx
    ex af,af'
    pop hl
    pop de
    pop bc
    pop af
    ei
    reti

_afx_play_isr_enabled:
    DEFB 1

_frame_counter:
    DEFB 0
