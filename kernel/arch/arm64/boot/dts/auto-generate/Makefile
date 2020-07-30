dtb-y += hi3650_hi3650_EVB3_VerC_config.dtb
dtb-y += hi3650_hi3650_fpga_081_3091_config.dtb
dtb-y += hi3650_hi3650_emulator_3099_config.dtb
dtb-y += hi3650_hi3650_Pilot2_DSDA_config.dtb
dtb-y += hi3650_hi3650_EVB2_VerB_config.dtb
dtb-y += hi3650_hi3650_1102_FPGA_config.dtb
dtb-y += hi3650_hi3650_fpga_080_3081_config.dtb
dtb-y += hi3650_hi3650_Pilot2_DSDS_config.dtb
dtb-y += hi3650_hi3650_udp_3001_config.dtb
dtb-y += hi3650_hi3650_fpga_082_3092_config.dtb
dtb-y += hi3650_hi3650_EVB3_VerB_X_config.dtb
dtb-y += hi3650_hi3650_EVB2_VerC_config.dtb
dtb-y += hi3650_hi3650_fpga_088_3098_config.dtb
dtb-y += hi3650_hi3650_fpga_080_3082_config.dtb
dtb-y += hi3650_hi3650_fpga_087_3097_config.dtb
dtb-y += hi3650_hi3650_EVB4_VerB_config.dtb
dtb-y += hi3650_hi3650_EVB3_VerB_config.dtb
dtb-y += hi3650_hi3650_1102_EVB_config.dtb
dtb-y += hi3650_hi3650_fpga_080_3080_config.dtb

targets += dtbs

dtbs: $(addprefix $(obj)/, $(dtb-y))
	$(Q)rm -f $(obj)/../*.dtb

clean-files := *.dtb
