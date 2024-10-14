void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__QX0_0,data__->OUT1,retain)
  __INIT_LOCATED_VALUE(data__->OUT1,0)
  __INIT_VAR(data__->TRU,1,retain)
  TP_init__(&data__->TP0,retain);
  TOF_init__(&data__->TOF0,retain);
  __INIT_VAR(data__->_TMP_NOT24_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 2500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,_TMP_NOT24_OUT,,!(__GET_VAR(data__->TOF0.Q,)));
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->_TMP_NOT24_OUT,));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 2500, 0, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_LOCATED(data__->,OUT1,,__GET_VAR(data__->TP0.Q,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





