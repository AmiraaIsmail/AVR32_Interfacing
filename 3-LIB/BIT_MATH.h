#define SET_BIT(var,bit) var|=(1<<bit)
#define CLR_BIT(var,bit) var&=(~(1<<bit))
#define TOG_BIT(var,bit) var^=(1<<bit)
#define GET_BIT(var,bit) ((var>>bit)&1)


