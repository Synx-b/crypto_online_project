/*
 * File: crypto_online_home.cc
 * Created: 19/12/2017 13:32
 * Finished:
 *
 * Description:
 *
 * Author: Jacob Powell
 */

#ifndef CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_NAVIGATION_GRID_H
#define CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_NAVIGATION_GRID_H

#include <Wt/WGridLayout.h>
#include <Wt/WText.h>
#include <Wt/WLink.h>
#include <Wt/WAnchor.h>

class crypto_online_navigation_grid : public Wt::WGridLayout {
public:
    crypto_online_navigation_grid();

private:

    void populate_navigation_grid();
    void setup_basic_contents();
    void setup_symmetric_contents();
    void setup_asymmetric_contents();
    void setup_applications_contents();
    void clear_grid();

    std::unique_ptr<Wt::WText> title_cryptography_basics;
    std::unique_ptr<Wt::WText> title_symmetric;
    std::unique_ptr<Wt::WText> title_asymmetric;
    std::unique_ptr<Wt::WText> title_applications;

    std::unique_ptr<Wt::WText> subtitle_introduction_to_symmetric_cryptography;
    std::unique_ptr<Wt::WText> subtitle_des;
    std::unique_ptr<Wt::WText> subtitle_aes;
    std::unique_ptr<Wt::WText> subtitle_more_about_block_ciphers;
    std::unique_ptr<Wt::WText> subtitle_introduction_to_asymmetric_cryptography;
    std::unique_ptr<Wt::WText> subtitle_basic_number_theory_for_pk;
    std::unique_ptr<Wt::WText> subtitle_rsa_cryptosystem;
    std::unique_ptr<Wt::WText> subtitle_dlp_cryptosystems;
    std::unique_ptr<Wt::WText> subtitle_ec_cryptosystems;
    std::unique_ptr<Wt::WText> subtitle_digital_signatures;
    std::unique_ptr<Wt::WText> subtitle_hash_functions;
    std::unique_ptr<Wt::WText> subtitle_macs;
    std::unique_ptr<Wt::WText> subtitle_key_establishment;

    std::unique_ptr<Wt::WAnchor> cryptography_basics_concepts;
    std::unique_ptr<Wt::WAnchor> cryptography_basics_real_world_applications;
    std::unique_ptr<Wt::WAnchor> cryptography_basics_concepts_history;

    std::unique_ptr<Wt::WAnchor> symmetric_modular_arithmetic;
    std::unique_ptr<Wt::WAnchor> symmetric_cipher_types;
    std::unique_ptr<Wt::WAnchor> symmetric_historical_ciphers;

    std::unique_ptr<Wt::WAnchor> symmetric_randomness;
    std::unique_ptr<Wt::WAnchor> symmetric_stream_ciphers;
    std::unique_ptr<Wt::WAnchor> symmetric_linear_feedback_shift_registers;

    std::unique_ptr<Wt::WAnchor> symmetric_des_overview;
    std::unique_ptr<Wt::WAnchor> symmetric_des_feistal_networks;
    std::unique_ptr<Wt::WAnchor> symmetric_des_internals;
    std::unique_ptr<Wt::WAnchor> symmetric_des_decryption;
    std::unique_ptr<Wt::WAnchor> symmetric_des_security;
    std::unique_ptr<Wt::WAnchor> symmetric_des_alternatives;

    std::unique_ptr<Wt::WAnchor> symmetric_aes_overview;
    std::unique_ptr<Wt::WAnchor> symmetric_aes_galois_fields;
    std::unique_ptr<Wt::WAnchor> symmetric_aes_internals;
    std::unique_ptr<Wt::WAnchor> symmetric_aes_decryption;
    std::unique_ptr<Wt::WAnchor> symmetric_aes_implementations_hardware_software;
    std::unique_ptr<Wt::WAnchor> symmetric_aes_example;

    std::unique_ptr<Wt::WAnchor> symmetric_more_about_block_ciphers_modes_of_operation;
    std::unique_ptr<Wt::WAnchor> symmetric_more_about_block_ciphers_increasing_security;
    std::unique_ptr<Wt::WAnchor> symmetric_more_about_block_ciphers_revisit_of_exhaustive_key_search;

    std::unique_ptr<Wt::WAnchor> asymmetric_symmetric_vs_asymmetric;
    std::unique_ptr<Wt::WAnchor> asymmetric_authenticity_of_public_keys;
    std::unique_ptr<Wt::WAnchor> asymmetric_key_lengths_and_security_levels;

    std::unique_ptr<Wt::WAnchor> asymmetric_euclidean_algorithm;
    std::unique_ptr<Wt::WAnchor> asymmetric_eulers_phi_function;
    std::unique_ptr<Wt::WAnchor> asymmetric_fermats_little_theorem_and_eulers_theorem;

    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_introduction;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_encryption_decryption;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_key_generation;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_encryption_decryption_fast_exponentiation;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_speed_up_techniques;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_finding_large_primes;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_padding;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_attacks;
    std::unique_ptr<Wt::WAnchor> asymmetric_rsa_implementations_in_hardware_software;

    std::unique_ptr<Wt::WAnchor> asymmetric_dh_dhke;
    std::unique_ptr<Wt::WAnchor> asymmetric_dh_algebra;
    std::unique_ptr<Wt::WAnchor> asymmetric_dh_dlp;
    std::unique_ptr<Wt::WAnchor> asymmetric_dh_security;
    std::unique_ptr<Wt::WAnchor> asymmetric_dh_elgamal_encryption_scheme;
    std::unique_ptr<Wt::WAnchor> asymmetric_dh_elgamal_security;

    std::unique_ptr<Wt::WAnchor> asymmetric_ec_definition;
    std::unique_ptr<Wt::WAnchor> asymmetric_ec_group_operations;
    std::unique_ptr<Wt::WAnchor> asymmetric_ec_dlp;
    std::unique_ptr<Wt::WAnchor> asymmetric_ec_dhke;
    std::unique_ptr<Wt::WAnchor> asymmetric_ec_security;
    std::unique_ptr<Wt::WAnchor> asymmetric_ec_implementations_in_hardware_software;

    std::unique_ptr<Wt::WAnchor> asymmetric_ds_introduction;
    std::unique_ptr<Wt::WAnchor> asymmetric_ds_rsa;
    std::unique_ptr<Wt::WAnchor> asymmetric_ds_elgamal;
    std::unique_ptr<Wt::WAnchor> asymmetric_ds_dsa;
    std::unique_ptr<Wt::WAnchor> asymmetric_ds_ecdsa;

    std::unique_ptr<Wt::WAnchor> protocols_hf_motivation;
    std::unique_ptr<Wt::WAnchor> protocols_hf_security_requirements;
    std::unique_ptr<Wt::WAnchor> protocols_hf_overview;
    std::unique_ptr<Wt::WAnchor> protocols_hf_sha1;
    std::unique_ptr<Wt::WAnchor> protocols_hf_sha3;
    std::unique_ptr<Wt::WAnchor> protocols_hf_bcrypt;

    std::unique_ptr<Wt::WAnchor> protocols_macs_principles;
    std::unique_ptr<Wt::WAnchor> protocols_macs_hash_functions;
    std::unique_ptr<Wt::WAnchor> protocols_macs_block_cipher;

    std::unique_ptr<Wt::WAnchor> protocols_key_est_introduction;
    std::unique_ptr<Wt::WAnchor> protocols_key_est_symmetric;
    std::unique_ptr<Wt::WAnchor> protocols_key_est_asymmetric;

};


#endif //CRYPTO_ONLINE_PROJECT_CRYPTO_ONLINE_NAVIGATION_GRID_H
