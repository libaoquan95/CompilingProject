_offset_main_0:
	BeginFunc 4 ;
	_tmp0 = 0 ;
	Return _tmp0 ;
	EndFunc ;
f_main:
main:
	BeginFunc 612 ;
	_tmp1 = 0 ;
	sz = _tmp1 ;
_L0:
	_tmp2 = 2 ;
	_tmp3 = sz < _tmp2 ;
	IfZ _tmp3 Goto _L1 ;
	_tmp4 = "Enter Number: " ;
	PushParam _tmp4 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp5 = LCall _ReadInteger ;
	sz = _tmp5 ;
	Goto _L0 ;
_L1:
	_tmp6 = 0 ;
	_tmp7 = 4 ;
	_tmp8 = _tmp6 < sz ;
	IfZ _tmp8 Goto _L2 ;
	Goto _L3 ;
_L2:
	_tmp9 = "Decaf runtime error: Array size is <= 0\n" ;
	PushParam _tmp9 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L3:
	_tmp10 = sz * _tmp7 ;
	_tmp11 = _tmp10 + _tmp7 ;
	PushParam _tmp11 ;
	_tmp12 = LCall _Alloc ;
	PopParams 4 ;
	*(_tmp12) = sz ;
	a = _tmp12 ;
	_tmp13 = 0 ;
	_tmp14 = 0 ;
	_tmp15 = 4 ;
	_tmp16 = *(a) ;
	_tmp17 = _tmp16 == _tmp13 ;
	_tmp18 = _tmp16 < _tmp13 ;
	_tmp19 = _tmp18 || _tmp17 ;
	_tmp20 = _tmp13 < _tmp14 ;
	_tmp21 = _tmp20 || _tmp19 ;
	IfZ _tmp21 Goto _L4 ;
	_tmp22 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp22 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L4:
	_tmp23 = _tmp13 * _tmp15 ;
	_tmp24 = _tmp23 + _tmp15 ;
	_tmp25 = a + _tmp24 ;
	_tmp26 = *(_tmp25) ;
	_tmp27 = 0 ;
	_tmp28 = 0 ;
	_tmp29 = 0 ;
	_tmp30 = 4 ;
	_tmp31 = *(a) ;
	_tmp32 = _tmp31 == _tmp28 ;
	_tmp33 = _tmp31 < _tmp28 ;
	_tmp34 = _tmp33 || _tmp32 ;
	_tmp35 = _tmp28 < _tmp29 ;
	_tmp36 = _tmp35 || _tmp34 ;
	IfZ _tmp36 Goto _L5 ;
	_tmp37 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp37 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L5:
	_tmp38 = _tmp28 * _tmp30 ;
	_tmp39 = _tmp38 + _tmp30 ;
	_tmp40 = a + _tmp39 ;
	*(_tmp40) = _tmp27 ;
	_tmp41 = 1 ;
	_tmp42 = 0 ;
	_tmp43 = 4 ;
	_tmp44 = *(a) ;
	_tmp45 = _tmp44 == _tmp41 ;
	_tmp46 = _tmp44 < _tmp41 ;
	_tmp47 = _tmp46 || _tmp45 ;
	_tmp48 = _tmp41 < _tmp42 ;
	_tmp49 = _tmp48 || _tmp47 ;
	IfZ _tmp49 Goto _L6 ;
	_tmp50 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp50 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L6:
	_tmp51 = _tmp41 * _tmp43 ;
	_tmp52 = _tmp51 + _tmp43 ;
	_tmp53 = a + _tmp52 ;
	_tmp54 = *(_tmp53) ;
	_tmp55 = 1 ;
	_tmp56 = 1 ;
	_tmp57 = 0 ;
	_tmp58 = 4 ;
	_tmp59 = *(a) ;
	_tmp60 = _tmp59 == _tmp56 ;
	_tmp61 = _tmp59 < _tmp56 ;
	_tmp62 = _tmp61 || _tmp60 ;
	_tmp63 = _tmp56 < _tmp57 ;
	_tmp64 = _tmp63 || _tmp62 ;
	IfZ _tmp64 Goto _L7 ;
	_tmp65 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp65 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L7:
	_tmp66 = _tmp56 * _tmp58 ;
	_tmp67 = _tmp66 + _tmp58 ;
	_tmp68 = a + _tmp67 ;
	*(_tmp68) = _tmp55 ;
	_tmp69 = 2 ;
	i = _tmp69 ;
_L8:
	_tmp70 = *(a) ;
	_tmp71 = i < _tmp70 ;
	IfZ _tmp71 Goto _L9 ;
	_tmp72 = 0 ;
	_tmp73 = 4 ;
	_tmp74 = *(a) ;
	_tmp75 = _tmp74 == i ;
	_tmp76 = _tmp74 < i ;
	_tmp77 = _tmp76 || _tmp75 ;
	_tmp78 = i < _tmp72 ;
	_tmp79 = _tmp78 || _tmp77 ;
	IfZ _tmp79 Goto _L10 ;
	_tmp80 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp80 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L10:
	_tmp81 = i * _tmp73 ;
	_tmp82 = _tmp81 + _tmp73 ;
	_tmp83 = a + _tmp82 ;
	_tmp84 = *(_tmp83) ;
	_tmp85 = 1 ;
	_tmp86 = i - _tmp85 ;
	_tmp87 = 0 ;
	_tmp88 = 4 ;
	_tmp89 = *(a) ;
	_tmp90 = _tmp89 == _tmp86 ;
	_tmp91 = _tmp89 < _tmp86 ;
	_tmp92 = _tmp91 || _tmp90 ;
	_tmp93 = _tmp86 < _tmp87 ;
	_tmp94 = _tmp93 || _tmp92 ;
	IfZ _tmp94 Goto _L11 ;
	_tmp95 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp95 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L11:
	_tmp96 = _tmp86 * _tmp88 ;
	_tmp97 = _tmp96 + _tmp88 ;
	_tmp98 = a + _tmp97 ;
	_tmp99 = *(_tmp98) ;
	_tmp100 = 2 ;
	_tmp101 = i - _tmp100 ;
	_tmp102 = 0 ;
	_tmp103 = 4 ;
	_tmp104 = *(a) ;
	_tmp105 = _tmp104 == _tmp101 ;
	_tmp106 = _tmp104 < _tmp101 ;
	_tmp107 = _tmp106 || _tmp105 ;
	_tmp108 = _tmp101 < _tmp102 ;
	_tmp109 = _tmp108 || _tmp107 ;
	IfZ _tmp109 Goto _L12 ;
	_tmp110 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp110 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L12:
	_tmp111 = _tmp101 * _tmp103 ;
	_tmp112 = _tmp111 + _tmp103 ;
	_tmp113 = a + _tmp112 ;
	_tmp114 = *(_tmp113) ;
	_tmp115 = _tmp99 + _tmp114 ;
	_tmp116 = 0 ;
	_tmp117 = 4 ;
	_tmp118 = *(a) ;
	_tmp119 = _tmp118 == i ;
	_tmp120 = _tmp118 < i ;
	_tmp121 = _tmp120 || _tmp119 ;
	_tmp122 = i < _tmp116 ;
	_tmp123 = _tmp122 || _tmp121 ;
	IfZ _tmp123 Goto _L13 ;
	_tmp124 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp124 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L13:
	_tmp125 = i * _tmp117 ;
	_tmp126 = _tmp125 + _tmp117 ;
	_tmp127 = a + _tmp126 ;
	*(_tmp127) = _tmp115 ;
	_tmp128 = 1 ;
	_tmp129 = i ;
	_tmp130 = _tmp129 + _tmp128 ;
	i = _tmp130 ;
	Goto _L8 ;
_L9:
	_tmp131 = 0 ;
	i = _tmp131 ;
_L14:
	_tmp132 = *(a) ;
	_tmp133 = i < _tmp132 ;
	IfZ _tmp133 Goto _L15 ;
	_tmp134 = 0 ;
	_tmp135 = 4 ;
	_tmp136 = *(a) ;
	_tmp137 = _tmp136 == i ;
	_tmp138 = _tmp136 < i ;
	_tmp139 = _tmp138 || _tmp137 ;
	_tmp140 = i < _tmp134 ;
	_tmp141 = _tmp140 || _tmp139 ;
	IfZ _tmp141 Goto _L16 ;
	_tmp142 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp142 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L16:
	_tmp143 = i * _tmp135 ;
	_tmp144 = _tmp143 + _tmp135 ;
	_tmp145 = a + _tmp144 ;
	_tmp146 = *(_tmp145) ;
	PushParam _tmp146 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp147 = " " ;
	PushParam _tmp147 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp148 = 1 ;
	_tmp149 = i ;
	_tmp150 = _tmp149 + _tmp148 ;
	i = _tmp150 ;
	Goto _L14 ;
_L15:
	EndFunc ;
