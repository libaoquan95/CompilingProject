_offset_main_0:
	BeginFunc 4 ;
	_tmp0 = 0 ;
	Return _tmp0 ;
	EndFunc ;
f_main:
main:
	BeginFunc 8 ;
	_tmp1 = LCall _ReadInteger ;
	_tmp2 = LCall _ReadInteger ;
	PushParam _tmp2 ;
	LCall _PrintInt ;
	PopParams 4 ;
	EndFunc ;
