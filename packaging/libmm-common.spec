Name:       libmm-common
Summary:    Multimedia Framework Common Lib
%if 0%{?tizen_profile_mobile}
Version:    0.2.55
Release:    0
%else
Version:    0.3.1
Release:    0
%endif
Group:      TO_BE/FILLED_IN
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(mm-log)


%description
Multimedia Framework Common Library

%package devel
Summary:    Multimedia Framework Common Lib (devel)
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
Multimedia Framework Common Library (devel)

%prep
%setup -q

%if 0%{?tizen_profile_wearable}
cd wearable
%else
cd mobile
%endif
./autogen.sh
CFLAGS="%{optflags} -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" " ./configure --prefix=%{_prefix} ; export CFLAGS

%build


%if 0%{?tizen_profile_wearable}
cd wearable
%else
cd mobile
%endif
make %{?jobs:-j%jobs}

%install

%if 0%{?tizen_profile_wearable}
cd wearable
%else
cd mobile
%endif
rm -rf %{buildroot}
mkdir -p %{buildroot}/usr/share/license
cp LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}
%make_install


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files

%if 0%{?tizen_profile_wearable}
%manifest wearable/libmm-common.manifest
%else
%manifest mobile/libmm-common.manifest
%endif
%defattr(-,root,root,-)
%{_libdir}/libmmfcommon.so.*
%{_datadir}/license/%{name}


%files devel
%defattr(-,root,root,-)
%{_includedir}/mmf/SLP_MultimediaFW_PG.h
%{_includedir}/mmf/mm_types.h
%{_includedir}/mmf/mm_error.h
%{_includedir}/mmf/mm_message.h
%{_includedir}/mmf/mm_attrs.h
%{_includedir}/mmf/mm_attrs_private.h
%{_includedir}/mmf/mm_debug.h
%{_includedir}/mmf/mm.h
%{_libdir}/pkgconfig/mm-common.pc
%{_libdir}/libmmfcommon.so
