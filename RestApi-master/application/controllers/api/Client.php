<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 *
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Client extends REST_Controller 
{

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Client_model');
    }

    public function client_get($id=NULL)
    {
        // user from a data store e.g. database

       // $id = $this->get('idClient');
       $id = $this->uri->segment(4);
        // If the id parameter doesn't exist return all users
        if ($id === NULL)
        {
            $client=$this->Client_model->get_client(NULL);
            // Check if the client data store contains client (in case the database result returns NULL)
            if ($client)
            {
                // Set the response and exit
                $this->response($client, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No clients were found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular client.
        else 
        {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the client from the database, using the id as key for retrieval.
            $client=$this->Client_model->get_client($id);
            if (!empty($client))
            {
                $this->set_response($client, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'client could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function client_post()
    {
        // Add a new client
       
        $clear_password=$this->post('passw');
        $encrypted_pass = password_hash($clear_password,PASSWORD_DEFAULT);
        $add_data=array(
            'username'      =>$this->post('username'),
            'passw'         =>$encrypted_pass,
            'balance'       => $this->post('balance'),
            'id_account'    => $this->post('id_account'),
            'accTy'         => $this->post('accTy')                  //if ($this=='DEBIT') {->post($debit)} else {->post($credit)}
        );
        
        $insert_id=$this->Client_model->add_client($add_data);
        
        if($insert_id) 
        {
            $message = [
             //   'Client ID'         => $this->db->query('SELECT idClient FROM client WHERE idClient=(SELECT MAX(idClient) FROM client ORDER BY IdClient DESC LIMIT 1)'),
                'data_array'        =>  $add_data,
                'Message'           => 'Added a client'
                
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not add client data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }

    }
    public function client_put($id=NULL)
    {
        $id = $this->uri->segment(4);
        // Update the client
        //$id=$this->get('idClient');
        $clear_password=$this->put('password');
        $encrypted_pass = password_hash($clear_password,PASSWORD_DEFAULT);
        $update_data=array(
          'username'=>$this->put('username'),
          'password'=>$encrypted_pass
        );
        $result=$this->Client_model->update_client($id, $update_data);

        if($result)
        {
          $message = [
              'id_user' => $id,
              'username' => $this->put('username'),
              'password' => $this->put('password'),
              'message' => 'updated client'
          ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update client info'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }

    public function client_delete($id=NULL)
    {
        $id = $this->uri->segment(4);
        //$id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->Client_model->delete_client($id);
        if ($result)
        {
          $message = [
              'id_client' => $id,
              'message' => 'Deleted the client'
          ];
          $this->set_response($message, REST_Controller::HTTP_OK);
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not delete client'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }



}
