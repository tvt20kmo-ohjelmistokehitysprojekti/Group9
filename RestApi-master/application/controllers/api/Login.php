<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller 
{
  public function check_login(){
    $this->load->model('Client_model');
    $idClient=$this->input->get('idClient');
    $plaintext_password=$this->input->get('password');
    $encrypted_password=$this->Client_model->check_login($idClient);

    if(password_verify($plaintext_password,$encrypted_password)){
      $result=true;
    }
    else{
      $result=false;
    }
    echo json_encode($result);
  }
}
