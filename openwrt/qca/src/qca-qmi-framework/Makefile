INCLUDE_DIR += -I./inc -I./common/inc -I./smem_log  -I./qcci/inc -I ./qrtr/lib -I ./qrtr/src
QMI_SRC_DIR := common/src
QMI_CCI_DIR := qcci/src
SMEM_LOG_DIR := smem_log
LIB := -lpthread -shared
FLAGS = -fPIC -g
LDFLAGS += $(TARGET_LDFLAGS)
EXTRA_CFLAGS = $(CPPFLAGS) $(CFLAGS) -fstack-protector-all


libqmicommon := $(QMI_SRC_DIR)/common_v01.c
libqmicci := $(QMI_CCI_DIR)/qmi_cci_common.c \
	$(QMI_CCI_DIR)/qmi_cci_target.c \
	$(QMI_CCI_DIR)/qmi_cci_xport_qrtr.c \
	$(QMI_CCI_DIR)/qmi_cci_xport_ipc_router.c \
	encdec/qmi_idl_lib.c encdec/qmi_idl_accessor.c \

all: qmi-common qcci-ipcrtr qcci-qrtr
	mkdir -p lib
	mv libqmi_common_so.so lib/
	mv libqmi_cci.so lib/
	mv libqmi_qrtr_cci.so lib/
	$(MAKE) ARCH="$(ARCH)" CROSS_COMPILE="$(CC)" LDFLAGS="$(LDFLAGS)" CFLAGS="$(EXTRA_CFLAGS)" -C qrtr/ all

qmi-common:
	$(CC) -o libqmi_common_so.so $(libqmicommon) $(FLAGS) $(INCLUDE_DIR) $(LIB) -znow -zrelro

qcci-ipcrtr:
	$(CC) -o libqmi_cci.so $(libqmicci) $(FLAGS) $(LDFLAGS) $(EXTRA_CFLAGS) $(INCLUDE_DIR) $(LIB) -Llibqmi_common_so.so

qcci-qrtr:
	$(CC) -o libqmi_qrtr_cci.so $(libqmicci) $(FLAGS) $(LDFLAGS) $(EXTRA_CFLAGS) -DQCCI_QRTR=1 $(INCLUDE_DIR) $(LIB) -Llibqmi_common_so.so

clean:
	rm -rf lib/
	rm -rf *.o
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CC) -C qrtr/ clean
