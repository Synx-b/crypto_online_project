
# Sources for the project

set(WT_PROJECT_SOURCE main.cc layout/crypto_online_home.cc layout/crypto_online_home.h layout/header/crypto_online_header.cc layout/header/crypto_online_header.h layout/crypto_online_navigation_grid.cc layout/crypto_online_navigation_grid.h layout/crypto_online_footer.cc layout/crypto_online_footer.h db/db_user.cc db/db_user.h db/db_interface.cc db/db_interface.h db/db_roles.h layout/crypto_online_profile.cc layout/crypto_online_profile.h crypto/aes_implementation.cc crypto/aes_implementation.h layout/information_content/learning_content_template.cc layout/information_content/learning_content_template.h layout/information_content/modular_arithmetic.cc layout/information_content/modular_arithmetic.h layout/information_content/intro_to_cryptography.cc layout/information_content/intro_to_cryptography.h db/session.cc db/session.h crypto_online_launcher.cc crypto_online_launcher.h auth/crypto_online_auth_widget.cc auth/crypto_online_auth_widget.h auth/crypto_online_register_widget.cc auth/crypto_online_register_widget.h db/db_user_answered_question.h db/db_questions.h layout/crypto_online_aes_example.cc layout/crypto_online_aes_example.h)

set(WT_PROJECT_TARGET project.wt)

add_executable(${WT_PROJECT_TARGET} ${WT_PROJECT_SOURCE})

target_link_libraries(${WT_PROJECT_TARGET}
        /home/synx/wt-4.0.2/dbobuild/src/Wt/Dbo/libwtdbo.so
        /home/synx/wt-4.0.2/dbobuild/src/Wt/Dbo/backend/libwtdbosqlite3.so
        /home/synx/wt-4.0.2/dbobuild/src/Wt/Dbo/backend/libwtdbofirebird.so
        /home/synx/wt-4.0.2/dbobuild/src/Wt/Dbo/backend/libwtdbopostgres.so
        /home/synx/wt-4.0.2/build/src/libwt.so
        /home/synx/wt-4.0.2/build/src/http/libwthttp.so
        /home/synx/cryptopp565/libcryptopp.so
        //usr/lib/x86_64-linux-gnu/libboost_system.so)

include_directories(/home/synx/cryptopp565
        /home/synx/wt-4.0.2/src
        /home/synx/wt-4.0.2/build)