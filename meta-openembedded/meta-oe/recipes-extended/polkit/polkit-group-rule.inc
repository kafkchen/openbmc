# polkit must prepare polkitd group
DEPENDS += "polkit"

inherit distro_features_check
REQUIRED_DISTRO_FEATURES = "polkit"

inherit useradd

do_install_prepend() {
    install -m 700 -d ${D}${sysconfdir}/polkit-1/rules.d
    chown polkitd:polkitd ${D}${sysconfdir}/polkit-1/rules.d
}
USERADD_PARAM_${PN}_prepend = "--system --no-create-home --user-group --home-dir ${sysconfdir}/polkit-1 polkitd;"
