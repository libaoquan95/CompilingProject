_offset_main_0:
	BeginFunc 4 ;
	_tmp0 = 0 ;
	Return _tmp0 ;
	EndFunc ;
f_main:
main:
	BeginFunc 52 ;
	_tmp1 = 42 ;
	_tmp2 = 137 ;
	_tmp3 = _tmp1 + _tmp2 ;
	_tmp4 = _tmp3 ;
	PushParam _tmp3 ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam _tmp3 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp6 = 3 ;
	_tmp7 = 4 ;
	_tmp8 = _tmp6 + _tmp7 ;
	PushParam _tmp8 ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam _tmp6 ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam _tmp7 ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam _tmp6 ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam _tmp7 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp9 = _tmp8 ;
	_tmp10 = _tmp3 + _tmp8 ;
	PushParam _tmp10 ;
	LCall _PrintInt ;
	PopParams 4 ;
	EndFunc ;