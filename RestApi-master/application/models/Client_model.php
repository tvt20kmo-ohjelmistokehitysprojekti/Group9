<?php
/**
 *
 */
class Client_model extends CI_model
{
  function get_client($id){
    $this->db->select('*');
    $this->db->from('client');
    if($id !== NULL) {
      $this->db->where('idClient',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_client($add_data){
    $this->db->query("CALL add_client (?,?,?,?,?)",$add_data);
    if($this->db->affected_rows()!==NULL){
      return $this->db->affected_rows();
    }
    else {
      return FALSE;
    }
  }
  function update_client($id, $update_data){
    $this->db->where('idClient',$id);
    $this->db->update('client',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function delete_client($id){
    $this->db->where('idClient',$id);
    $this->db->delete("client");

    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function check_login($idClient){
    $this->db->select('Password');
    $this->db->from('client');
    $this->db->where('idClient',$idClient);
    return $this->db->get()->row('Password');
  }

  function get_idAccount($idClient, $accType){
    $this->db->select('idAccount');
    $this->db->from('account');
    $this->db->where('idClient', $idClient);
    $this->db->where('accountType', $accType);
    
    return $this->db->get()->result();
  }
}