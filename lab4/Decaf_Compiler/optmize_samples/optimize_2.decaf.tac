_offset_main_0:
	BeginFunc 4 ;
	_tmp0 = 0 ;
	Return _tmp0 ;
	EndFunc ;
f_main:
main:
	BeginFunc 104 ;
	_tmp1 = 42 ;
	a = _tmp1 ;
	_tmp2 = 137 ;
	b = _tmp2 ;
	_tmp3 = a + b ;
	c = _tmp3 ;
	_tmp4 = a + b ;
	d = _tmp4 ;
	PushParam c ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam d ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp5 = 84 ;
	a = _tmp5 ;
	_tmp6 = a + b ;
	c = _tmp6 ;
	PushParam c ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp7 = 84 ;
	d = _tmp7 ;
	e = d ;
	f = e ;
	PushParam d ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam e ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam f ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp8 = 166 ;
	e = _tmp8 ;
	f = e ;
	PushParam f ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam e ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp9 = e + f ;
	c = _tmp9 ;
	_tmp10 = e + f ;
	d = _tmp10 ;
	_tmp11 = e + f ;
	f = _tmp11 ;
	_tmp12 = e + f ;
	g = _tmp12 ;
	_tmp13 = e + f ;
	h = _tmp13 ;
	_tmp14 = e + f ;
	i = _tmp14 ;
	_tmp15 = e + f ;
	j = _tmp15 ;
	PushParam f ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam g ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam h ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam i ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam j ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp16 = e + f ;
	f = _tmp16 ;
	PushParam c ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam d ;
	LCall _PrintInt ;
	PopParams 4 ;
	PushParam f ;
	LCall _PrintInt ;
	PopParams 4 ;
	EndFunc ;